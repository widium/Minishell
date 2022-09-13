/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/13 10:40:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_token *tokenizer_word(char *content, int id)
{
    t_token *token;

    token = create_token_word(content, id);
    return (token);
}

t_arg *tokenizer_arg(char *line, int start, int end, int id)
{
    t_arg *arg;
    char *content;
    
    if (line == NULL)
        content = NULL;
    else
        content = malloc_substrcpy(line, start, (end - start) + 1);
    arg = create_arg(content, id);
    return (arg);
}

void tokenize_word_arg(t_env *env, t_cmd *cmd, char *content)
{
    t_arg *arg;
    
    if (is_valide_argument(env, content))
    {
        arg = create_arg(content, TOKEN_WORD);
        add_arg_list(cmd, arg); 
    }
    else
        free(content);
    
}

t_token *tokenizer_bool(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;
    char *first;
    char *second;
    int i;
    
    i = start - 1;
    while (line[i] && !(is_boolean_operator(line, i)))
        i--;
    i++;
    first = malloc_substrcpy(line, i, (start - i));
    i = end + 1;
    while (line[i] && !(is_boolean_operator(line, i)))
        i++;
    i--;
    second = malloc_substrcpy(line, end + 1, (i - end));

    content = malloc_substrcpy(line, start, (end - start)+1);
    id = type_of_boolean(content);
    token = create_token_bool(content, first, second, id);
    return (token);
}

t_token *tokenizer_command(char *word, int id)
{
    t_token *token;

    token = create_token_command(id, word);
    return (token);
}

t_token *tokenizer_file(char *name, int id)
{
    t_token *token;
    int fd;

    fd = open(name, O_RDONLY | O_WRONLY |  O_CREAT, 0777);
    if (fd < 0)
        printf("%s : so such file or directory\n", name);

    token = create_token_file(name, fd, id);
    return (token);
}

int next_file_tokenization(t_env *env, char *line, int index)
{
    t_token *token;
    int new_index;
    char *content;

    if (line_is_finish(line, index))
        return (index);
    new_index = file_detection(line, ++index);
    content = malloc_substrcpy(line, index, (new_index - index) + 1);
    token = tokenizer_file(content, TOKEN_FILE);
    add_chained_list(env, token);
    
    return (new_index);
}