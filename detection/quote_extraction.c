/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:01:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 10:35:53 by ebennace         ###   ########.fr       */
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
    arg = tokenizer_arg(line, start, end, TOKEN_SINGLE_QUOTE);
    add_arg_list(cmd, arg);
    return (end + 1);
}

int double_quotes_extraction(t_cmd * cmd, char *line, int index)
{
    t_arg *arg;
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
    content = malloc_substrcpy(line, start, (end - start) + 1);
    parse_double_quote(cmd, content);
    free(content);
    return (end + 1);
}

void parse_double_quote(t_cmd *cmd, char *content)
{
    int index;
    int new_index;

    new_index = 0;
    index = 0;
    while (content[index])
    {
        if (is_variable(content, index))
        {
            new_index = variables_extraction(cmd, content, index);
            index = new_index;
        }
        else
        {
            new_index = string_extraction(cmd, content, index);
            index = new_index;
        }
        index++;
    }
}