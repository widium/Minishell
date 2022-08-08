/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 10:49:08 by ebennace         ###   ########.fr       */
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
    
    content = malloc_substrcpy(line, start, (end - start) + 1);
    arg = create_arg(content, id);
    return (arg);
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

t_token *tokenizer_redir(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;
    char *limiter;
    int type;
    int i;

    content = malloc_substrcpy(line, start, (end - start) + 1);
    type = type_of_redirect(content);
    token = create_token_redir(type, content);
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

    // if (access(name, R_OK & W_OK & F_OK) == 0)
    // {
        
    // }