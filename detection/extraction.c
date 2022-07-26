/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:25:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/26 16:39:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int flags_extraction(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;
    
    end = index;
    start = index;
    while (line[index])
    {
        if (is_delimiter(line, index))
        {
            end = index -1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(line, index - 1)))
        end = index - 1;
    arg = tokenizer_arg(line, start, end, TOKEN_FLAGS);
    add_arg_list(cmd, arg);
    return (end);
}

int variables_extraction(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;

    end = index;
    start = index;
    if (line[index + 1] == '$')
        return (index + 1);
    index++;
    while (line[index])
    {
        if (is_delimiter(line, index))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(line, index - 1)))
        end = index - 1;
    arg = tokenizer_arg(line, start + 1, end, TOKEN_VARIABLE);
    add_arg_list(cmd, arg);
    return (end);
}

int word_argument_extraction(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;

    start = index;
    end = index;
    while (line[index])
    {
        if (is_delimiter(line, index) || is_quote(line[index]))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(line, index - 1)))
        end = index - 1;
    arg = tokenizer_arg(line, start, end, TOKEN_WORD);
    add_arg_list(cmd, arg);
    return (end);
}

int string_extraction(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;

    start = index;
    end = index;
    while (line[index])
    {
        if (is_double_quote(line[index]) || is_variable(line, index))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_double_quote(line[index])) || !(is_variable(line, index)))
        end = index - 1;
    arg = tokenizer_arg(line, start, end, TOKEN_STRING);
    add_arg_list(cmd, arg);
    return (end);
}