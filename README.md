# Minimalist Bash Prompt
- [Get Started](#get-started)
- [Understanding the project structure](#understanding-the-project-structure)
- [Parser](#parser)
  - [1. Parser Type Detection](#parser-type-detection)
  - [2. Parser Extraction](#parser-extraction)
  - [3. Parser Classification](#parser-classification)
- [Tokenizer](#tokenizer)
  - [1. Token class](#token-class)
  - [2. Example of Structure](#example-of-structure)
  - [3. Create Token](#create-token)
  - [4. Chained Token Bidirectional](#chained-token-bidirectional)
  - [5. Env variable structure](#env-variable-structure)
   - [5.1 Construire une t_var a partir d'une String](construire-une-t_var-a-partir-d-une-string)
- [Theorical Utils](#theorical-utils)
***
![ezgif com-gif-maker](https://user-images.githubusercontent.com/85416801/193201839-19b1a2d4-73d5-4c6d-9264-7eb79829c24e.gif)
***
# Get Started
## Dependancy
- Arch
~~~bash
sudo pacman -Syu readline
~~~
- MacOS
~~~bash
brew install readline
~~~
- add in header file
~~~C
# include <readline/readline.h>
# include <readline/history.h>
add -lreadline with compilation
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
- ## Parser Extraction
	![](https://i.imgur.com/teLmxbE.png)
- ## Parser Classification
	![](https://i.imgur.com/uYLGKNl.png)
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
 - ## Env variable structure
	![](https://i.imgur.com/BW2xbwu.png)
### Construire une t_var a partir d'une String
~~~C
VARIABLE_NAME=VALUE
~~~
~~~C
name = get_variable_name(env_variable[index]);
value = get_env_variable_value(env_variable[index]);
var = init_env_variable(name, value, VALUE);
~~~
- #### Extraire le nom d'une variable
- #### Extraire la valeur d'une variable
- #### Construire la structure d'un t_var
~~~C
"var numero 48" :

 ---[SHELL]---
 | type : [1]
 | index : [48]
 | value : [/bin/bash]
 ----------------
~~~

### Convertir toute les variables d'environnement en t_var 
- **Iterez** dans chacune des variable d'envrionnement
	- [[Extraire le nom d'une variable]]
	- [[Extraire la valeur d'une variable]]
	- [[Construire la structure d'un t_var]]
	- [[create_chained_list() - C|add_chained_list]]
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
# Theorical Utils
***
