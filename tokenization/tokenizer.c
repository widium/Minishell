/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/19 19:04:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_token *tokenizer(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;
    
    content = ft_substr(line, start, (end - start) + 1);
    printf("%s : is_bin -> %d\n", content, is_bin(content));
    printf("wc is_bin : %d\n",(access("/bin/wc", X_OK & F_OK)));
    token = create_token(content, id);
    return (token);
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
    first = ft_substr(line, i, (start - i));
    i = end + 1;
    while (line[i] && !(is_boolean_operator(line, i)))
        i++;
    i--;
    second = ft_substr(line, end + 1, (i - end));

    content = ft_substr(line, start, (end - start)+1);
    token = create_token_bool(content, first, second, id);
    return (token);
}

t_token *tokenizer_redir(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;
    int type;
    int i;

    content = ft_substr(line, start, (end - start) + 1);
    type = type_of_redirect(content);
    token = create_token_redir(id, type, 0, 1, content);
    return (token);
}

t_token *tokenizer_variable(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;

    content = ft_substr(line, start, (end - start) + 1);
    token = create_token_variable(id, content);
    return (token);
}

t_token *tokenizer_command(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;

    content = ft_substr(line, start, (end - start) + 1);
    token = create_token_command(id, content);
    return (token);
}