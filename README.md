# Minimalist Bash Prompt
- [1. Get Started](#get-started)
- [2. Understanding the project structure](#understanding-the-project-structure)
- [3. Parser](#parser)
  	- [1. Parser Type Detection](#parser-type-detection)
  	- [2. Parser Extraction](#parser-extraction)
  	- [3. Parser Classification](#parser-classification)
- [4. Tokenizer](#tokenizer)
  	- [1. Token class](#token-class)
  	- [2. Example of Structure](#example-of-structure)
  	- [3. Create Token](#create-token)
  	- [4. Chained Token Bidirectional](#chained-token-bidirectional)
- [5. Env variable structure](#env-variable-structure)
  	- [1.Construire un t_var avec une String](#construire-un-t_var-avec-une-string)
  		- [1.Extraire le nom d une variable](#extraire-le-nom-d-une-variable)
  		- [2.Extraire la valeur d une variable](#extraire-la-valeur-d-une-variable)
  		- [3.Construire la structure t_var](#construire-la-structure-t_var)
  		- [4.Ajouter le t_var a la list de variables](#ajouter-le-t_var-a-la-list-de-variables)
  	- [2.Convertir toute les variables environnement en t_var](#convertir-toute-les-variables-environnement-en-t_var)
- [6. Execution](#execution)
***
![ezgif com-gif-maker](https://user-images.githubusercontent.com/85416801/193201839-19b1a2d4-73d5-4c6d-9264-7eb79829c24e.gif)
***
# Get Started
## Dependancy
###  Arch
~~~bash
sudo pacman -Syu readline
~~~
- add flags in Makefile
~~~bash
-lreadline
~~~
### MacOS
- install brew 
~~~bash
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
~~~
- install readline
~~~bash
brew install readline
~~~
- change flags in makefile
~~~bash
"add when Create .o file"
FLAGS += -I$(HOME)/.brew/opt/readline/include
"add in compilation"
READLINE += -L$(HOME)/.brew/opt/readline/lib
~~~
***
# Understanding the project structure
![](https://i.imgur.com/mTEApbZ.png)

~~~C
void prompt(t_env *env, char *line)
{
	parsing(env, line);
	check_error_parsing(env);
	if (doesnt_have_error_parsing)
	{
		processing_cmd(env);
		processing_redirection(env);
		if (doesnt_have_error_processing)
			execution(env);
	}
	remove_all_token(env);
	reset_counter_error(env);
	free(line);
}
~~~
***
# Parser
![](https://i.imgur.com/s7VvwbT.png)
- ## Parser Type Detection
	![](https://i.imgur.com/4RxjAlf.png)
~~~bash
echo "salut$HOME"
~~~
~~~C
if (is_word(env, line, start))
{ 
	end = word_extraction(env, line, start);
	content = malloc_substrcpy(line, start, end);
}
~~~
### Tester chaque index avec des fonction de detection de type :
~~~bash
echo "salut$HOME"
^
|
index = 0
~~~
- `is_word()` definie quel attributs comporte un mot :
	- **ne commence pas** par une quote `' "`
	- **ne commence pas par** un characteres vide `space \n \t`
	- **ne commence pas par** une paranthese `(`
	- **ne commence pas par** un separateur `> < >> | && ||`
	- **ne commence pas par** une Variables d'environnement
	- **ne commence pas par** un `$`
- La fonction **nous retourne 1** on peut alors recuperer le contenue du mot :
~~~C
int is_word(t_env *env, char *line, int i)
{
    if (!(is_quote(line[i])) && !(is_blank(line[i])) &&
     !(is_paranthesis(line, i)) && !(is_separator(line, i)) &&
     !(is_variable(env, line, i)) && line[i] != '$')
        return (1);
    return (0);
}
~~~
- On peut alors definir plein de **fonction de detection de type** pour 
	- **faciliter** sont parsing 
	- **separer** chaque concept en evitant d'influencer les autres :
~~~C
int is_NULL(char *line);
int is_input_chevrons(char *line, int i);
int is_output_chevrons(char *line, int i);
int is_pipe(char *line, int index);
int is_append_chevrons(char *line, int i);
int is_heredoc(char *line, int i);
int is_file_redirection(char *line, int i);
int is_redirection(char *line, int i);
int is_boolean_operator(char *line, int i);
~~~
- ## Parser Extraction
	![](https://i.imgur.com/teLmxbE.png)
#### Une fois qu'un mot est detecter on va l'**extraire** de la string :
~~~bash
echo "salut$HOME"
^
|
start = 0
~~~

- Pour savoir **quand s'arreter** on doit definir ==un type de caracteres de separation==
- dans ce cas on utilise la fonction **`is_delimiter()`**
~~~C
int is_delimiter(t_env *env, char *line, int index)
{
    if (is_blank(line[index]) || is_paranthesis(line, index) ||
     is_separator(line, index) || is_variable(env, line, index))
        return (1);
    return (0);    
}
~~~
- cette fonction **retournera 1 lorsque le caracteres actuel sera un delimiteur de mot** 
- recuperer **le dernier `index - 1 `** pour ne pas recuperer le caracters de separation 
- **extraire le contenue avec l'index de debut et l'index de fin du mot** 
~~~C
malloc_substrcpy(line, start, end)
~~~
~~~bash
echo "salut$HOME"
^  ^
|  |
s  e
~~~
~~~C
int word_extraction(t_env *env, char *line, int index)
{
    int start;

    start = index;
    while (line[index])
    {
        if (is_delimiter(env, line, index))
        {
            return (index - 1);
        }
        index++;
    }
    return (index);
}
~~~
- ## Parser Classification
	![](https://i.imgur.com/uYLGKNl.png)
### Une fois Le [Parser Extraction](#parser-extraction)  on doit classifier le contenue 
~~~bash
content = echo
~~~
- Comme pour le  [Parser Type Detection](#parser-type-detection)  on doit definir **une fonction de detection de type** 
- Dans ce cas on doit **classifier le mot** :
- Il sera definit comme **une command ou comme un simple mot**
~~~C
if (is_cmd(env, content))
	token = command_tokenization(env, line, content, ++new_index);
else
	token = tokenizer_word(content, TOKEN_WORD);

add_token_list(env, token);
~~~
- `is_cmd()` permet de Tester si le mot **est un binaire ou un built_in** :
~~~C
int is_cmd(t_env *env, char *word)
{
    if (is_bin(env, word) || is_built_in(word))
        return (1);
    return (0);
}

"echo is cmd"
~~~
- `is_bin()` test si **le path absolue ou simple** est valable
- `is_built_in()` test tout simplement **si le `content` est le meme qu'un built_in**
~~~C
int is_bin(t_env *env, char *word)
{
    char **bins;

    bins = get_env_bins(env);
    if (test_absolute_bin_access(word))
        return (1);
    else if (test_bin_access(bins, word))
        return (1);
    return (0);
}


int is_built_in(char *content)
{
    if (same_str(content, "echo", ft_strlen(content)))
	    return (1); 
    if (same_str(content, "cd", ft_strlen(content)))
	    return (1);
    if (same_str(content, "pwd", ft_strlen(content)))
	    return (1);
    if (same_str(content, "env", ft_strlen(content)))
	    return (1);
    if (same_str(content, "export", ft_strlen(content)))
	    return (1);
    if (same_str(content, "unset", ft_strlen(content)))
	    return (1);
    if (same_str(content, "exit", ft_strlen(content)))
	    return (1);
	return (0);
}
~~~
***
# Tokenizer
 - ## Token Class
	![](https://i.imgur.com/8hK8OtJ.png)
	- ### *Stocker un Nombre variable d'information*
		- avec l'Attribut `class` de la struct `t_token` on peut **stocker une autre struct avec differentes information :**
		- On **initialise une struct** dans le `void *`
~~~C
token->class = init_cmd();

t_cmd *init_cmd(char *content, int id)
~~~

![](https://i.imgur.com/2H2njja.png)

- ### *Assigner une struct aux  `Void *`:*
	pour stocker une struct dans le `Void *` on retourne une struct malloc avec le stockage de toutes ses valeur :
~~~C
t_token *create_token(char *content, int id)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = choose_class(content, id);
	
	return (token);
}

void *choose_class(char *content, int id)
{
    if (id == TOKEN_BLANK)
		return (init_blank(content, id));
    else if (id == TOKEN_WORD)
        return (init_word(content, id));
	return (NULL);
}
~~~
- ### *Definir un ID pour chaque token :*
	- Pour utiliser des **Condition de teste de type** et eviter les erreur
	- on assigne un **`id`** qui **defini le type de struct stocker** :
~~~C
# define TOKEN_NULL 0
# define TOKEN_BLANK 1
# define TOKEN_WORD 2
# define TOKEN_SINGLE_QUOTE 3
# define TOKEN_DOUBLE_QUOTE 4
# define TOKEN_PARANTHESIS 5
# define TOKEN_COMMAND 6
~~~
- **Tester Avant de recuperer les information :**
~~~C
t_cmd *cmd;

if (token->id == TOKEN_CMD)
	print_token_cmd(token)
~~~

- ### *Recuperer la struct de class avec du Cast:*
	- Pour recuperer les valeurs dans la struct qui est stocker dans un `Void \*` il faut **la [[Cast]] avec le nom de la struct** qui devrait lui etre assigner .
	- Pour savoir **quel type est le void * on peut utiliser un `id`** qui definit quel struct utiliser :
	- On cast directement le `void \*` avec *le type de la struct* **`((t_cmd *)token->class)->content`**
~~~C
t_cmd *cmd;

if (token->id == TOKEN_CMD)
	cmd = get_class(token);
~~~
~~~C
void *get_class(t_token *token)
{
    if (is_token_cmd(token))
    {
        return ((t_cmd *)token->class);
    }
    else if (is_token_redirection(token))
    {
        return ((t_redir *)token->class);
    }
    else if (is_token_file(token))
    {
        return ((t_file *)token->class);
    }
    else if (is_token_word(token))
    {
        return ((t_word *)token->class);
    }
    return (NULL);
}

~~~
 - ## Example of Structure
	![](https://i.imgur.com/uj4jPU8.png)
	- Grace a [Token class](#token-class) qui peut stocker une **structure variable d'information** , on peut **definir des tokens different** 
	- Dans l'exemple :
~~~bash
echo salut tonton | wc -l
~~~
- On definie **3 class** :
	- 2 **token** de *command*
	- 1 **token** de *redirection* 
- Chaque [Token class](#token-class) different on **des attributs tres variable** ce qui permet **d'etre beaucoup plus organiser sur l'execution !**
 - ## Create Token
 	- ### *Definir la class de Tokenization  :*
	- Apres avoir [Parser Classification](#parser-classification) on doit tokenizer le `content` avec sa class :
	- On **creer un token** avec **sa struct assigner grace a la classification** :
		- **Assigner** l'ID du token `token->id` par apport aux `content`
		- stocker la struct dans `class`
~~~C
t_token *token = create_token_command(content, TOKEN_CMD);
~~~
~~~C
t_token *create_token_command(char *content, int id)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = init_cmd(content, id);
	
	return (token);
}
~~~
~~~C
t_cmd   *init_cmd(char *content, int id)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
        return (NULL);
	cmd->id = id;
	cmd->content = content;
	cmd->flags = NULL;
	cmd->bin = NULL;
	cmd->arg = NULL;
	cmd->args = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->first_arg = NULL;
	cmd->pid = 0;
	return (cmd);
}
~~~
- ## Chained Token Bidirectional 
	- chaques token possede un pointeur sur le token precedent et sur le suivant
	- Ce qui permet d'iterer dans les 2 sens
~~~C
typedef struct s_token
{
    void *class;
    int id;
    struct s_token *next;
    struct s_token *prev;

}   t_token;
~~~
![](https://i.imgur.com/SVWS0Wc.png)
***
### *Ajouter des TOKEN dans la list :*
- **Recuperer** le Premier node dans l'env
	- **Si** il existe pas -> **le creer** 
	- **Sinon** iterer dans les token jusqu'aux dernier et **le connecter avec le precedent** 
~~~C
void add_token_list(t_env *env, t_token *token)
{
    t_token *iter;
    
    if (!(env->first_token))
        env->first_token = token;
    else 
    {
        iter = env->first_token;
        while (iter->next)
            iter = iter->next;
        connect_token(iter, token);
    }
}
~~~
- **Connecter dans les deux sens le `curr_token`**
~~~C
void connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}
~~~
 - # Env variable structure
	![](https://i.imgur.com/BW2xbwu.png)
- ## Construire un t_var avec une String
~~~C
VARIABLE_NAME=VALUE
~~~
~~~C
name = get_variable_name(env_variable[index]);
value = get_env_variable_value(env_variable[index]);
var = init_env_variable(name, value, VALUE);
~~~
~~~C
"var numero 48" :

 ---[SHELL]---
 | type : [1]
 | index : [48]
 | value : [/bin/bash]
 ----------------
~~~
- ## Extraire le nom d une variable
- **Extraire** le nom a partir de l'egal 
- **definir** la fin du nom 
	- **a l'index de l'egal - 1** 
	- **ou a la fin de la string**

~~~C
VARIABLE_NAME=VALUE
^           ^
|           |
"start"    "end"
~~~
~~~C
char	*get_variable_name(char *variable)
{
	int		index;
	int		start;
	int		end;
	char	*name;

	index = 0;
	start = 0;
	if (!variable)
		return (NULL);
	while (variable[index])
	{
		if (variable[index] == '=')
		{
			end = index - 1;
			name = malloc_substrcpy(variable, start, end);
			return (name);
		}
		index++;
	}
	end = index;
	name = malloc_substrcpy(variable, start, end);
	return (name);
}
~~~
- ## Extraire la valeur d une variable
- **Extraire** la valeur a partir de l'egal 
- **definir** le debut de la valeur 
	- **a l'index de l'egal + 1** 
- **definir la fin de la valeur a la fin de la string**
~~~C
VARIABLE_NAME=VALUE
	      ^    ^
              |    |
           "start" "end"
~~~
~~~C
char	*get_env_variable_value(char *variable)
{
	int		i;
	int		start;
	int		end;
	char	*value;

	i = 0;
	if (!variable)
		return (NULL);
	while (variable[i])
	{
		if (variable[i] == '=' && !(is_blank(variable[i + 1])))
		{
			start = i + 1;
			end = ft_strlen(variable);
			value = malloc_substrcpy(variable, start, end);
			if (is_value_null(value))
			{
				free(value);
				return (NULL);
			}
			return (value);
		}
		i++;
	}
	return (NULL);
}
~~~
- ## Construire la structure t_var
- **apres** avoir :
	- [Extraire le nom d une variable](#extraire-le-nom-d-une-variable)
  	- [Extraire la valeur d une variable](#extraire-la-valeur-d-une-variable)
	- **Definir** un ID qui defini si il y a une valeur ou non
~~~C
t_var	*init_env_variable(char *name, char *value, int id)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->index = -1;
	var->id = id;
	var->name = name;
	var->value = value;
	var->next = NULL;
	var->prev = NULL;
	return (var);
}
~~~
- ## Ajouter le t_var a la list de variables
~~~C
void	add_variables_list(t_env *env, t_var *var)
{
	t_var	*iter;
	int		i;

	i = 0;
	if (!(env->first_var))
	{
		env->first_var = var;
		var->index = i;
	}
	else
	{
		iter = env->first_var;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		var->index = i;
		connect_var(iter, var);
	}
}
~~~

## Convertir toute les variables environnement en t_var 
- **Iterez** dans chacune des variable d'envrionnement
	- [Extraire le nom d une variable](#extraire-le-nom-d-une-variable)
  	- [Extraire la valeur d une variable](#extraire-la-valeur-d-une-variable)
  	- [Construire la structure t_var](#construire-la-structure-t_var)
	- [Ajouter le t_var a la list de variables](#ajouter-le-t_var-a-la-list-de-variables)
~~~C
void	create_chained_var(t_env *env, char **env_variable)
{	
	int		index;
	char	*name;
	char	*value;
	t_var	*var;

	index = 0;
	while (env_variable[index])
	{
		name = get_variable_name(env_variable[index]);
		value = get_env_variable_value(env_variable[index]);
		var = init_env_variable(name, value, VALUE);
		add_variables_list(env, var);
		index++;
	}
}
~~~
***
# Execution
- Pour toute Theorie sur l'execution hesitez pas a checker ce repos [Pipex](https://github.com/widium/pipex)

![](https://i.imgur.com/8KkctLD.png)
~~~c
$> ls -la | wc
stock pid [ls]:[57253]
stock pid [wc]:[57254]
close [history.log]:[3]
close [ls]:[5]
close [wc]:[4]
------- Execution [ls process] --------
Wait [ls]:[57253]
DUP [ls]: fd_out [5], STDOUT_FILENO [1]
close [history.log]:[3]
close [ls]:[5]
close [wc]:[4]
------- Execution [wc process] --------
Wait [wc]:[57254]
DUP [wc] : fd_in [4], STDIN_FILENO [0]
close [history.log]:[3]
close [ls]:[5]
close [wc]:[4]

     27     238    1586

~~~

## Code :
~~~C
cmd = get_first_cmd(env);
while (cmd)
{
	bin_execution(env, cmd);
	cmd = get_next_cmd(cmd);
}
close_all_fd(env);
wait_all_pid(env);


void bin_execution(t_env *env, t_cmd *cmd)
{
    int pid;

    pid = fork();
    if (pid == 0)
    {
	redirect_cmd(cmd);
	close_all_fd(env);
	execve(path, args, variables);
    }
    else
    {
	stock_pid(cmd, id);
        return ;
    }
}

void wait_all_pid(t_env *env)
{
    t_token *token;
    t_cmd *cmd;
    int status;
    
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        waitpid(cmd->pid, &status, 0);
        token = get_next_token_cmd(token);
    }
}
~~~
***
