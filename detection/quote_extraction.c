/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:01:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/09 19:05:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int single_quotes_extraction(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;

    index++;
    start = index;
    end = index;
    while (line[index])
    {
        while (line[index] && is_back_slash(line[index]))
            index++;
        if (is_single_quote(line[index]))
        {
           end = index - 1;
           break; 
        } 
        index++;
    }
    if (is_finish(line[index]))
        arg = tokenizer_arg(NULL, 0, 0, TOKEN_NULL);
    else   
        arg = tokenizer_arg(line, start, end, TOKEN_SINGLE_QUOTE);
    add_arg_list(cmd, arg);
    return (end + 1);
}

int double_quotes_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
    int start;
    char *content;
    int end;

    index++;
    start = index;
    end = index;
    while (line[index])
    {
        while (line[index] && is_back_slash(line[index]))
            index++;
        if (is_double_quote(line[index]))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (is_finish(line[index]))
        content = NULL;
    else
        content = malloc_substrcpy(line, start, (end - start) + 1);
    parse_double_quote(env, cmd, content);
    return (end + 1);
}

void parse_double_quote(t_env *env, t_cmd *cmd, char *content)
{
    t_arg *arg;
    int index;
    int new_index;

    if (content == NULL)
    {
       arg = tokenizer_arg(NULL, 0, 0, TOKEN_NULL); 
       add_arg_list(cmd, arg);
       return ;
    }
    new_index = 0;
    index = 0;
    while (content[index])
    {
        if (is_variable(env, content, index))
        {
            new_index = variables_extraction(env, cmd, content, index);
            index = new_index;
        }
        else
        {
            new_index = string_extraction(env, cmd, content, index);
            index = new_index;
        }
        index++;
    }
}