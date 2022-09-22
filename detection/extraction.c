/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:25:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 10:55:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int flags_tokenization(t_env *env, t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;
    
    end = index;
    start = index;
    while (line[index])
    {
        if (is_delimiter(env, line, index))
        {
            end = index -1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(env, line, index - 1)))
        end = index - 1;
    arg = tokenizer_arg(line, start, end, TOKEN_FLAGS);
    add_arg_list(cmd, arg);
    return (end + 1);
}

int variables_extraction(t_env *env, t_cmd *cmd, char *line, int index)
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
        if (is_delimiter(env, line, index) || is_quote(line[index]))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(env, line, index - 1)))
        end = index - 1;
    arg = tokenizer_arg(line, start + 1, end, TOKEN_VARIABLE);
    add_arg_list(cmd, arg);
    return (end);
}

char *variable_detection(t_env *env, char *line, int index)
{
    int start;
    int end;
    char *name;

    end = index;
    start = index;
    if (line[index + 1] == '$')
        return (NULL);
    index++;
    while (line[index])
    {
        if (is_delimiter(env, line, index))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_delimiter(env ,line, index - 1)))
        end = index - 1;
    name = malloc_substrcpy(line, start, (end - start) + 1);
    return (name);
}

int word_argument_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
    char *content;
    int start;
    int end;

    start = index;
    end = index;
    while (line[index])
    {
        if (is_word_argument_separator(env, line, index))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_word_argument_separator(env, line, index)))
        end = index -1;
    content = malloc_substrcpy(line, start, (end - start) + 1);
    tokenize_word_arg(env, cmd, content);
    return (end);
}

int string_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;

    start = index;
    end = index;
    while (line[index])
    {
        if (is_double_quote(line[index]) || is_variable(env, line, index))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    if (!(is_double_quote(line[index])) || !(is_variable(env, line, index)))
        end = index - 1;
    arg = tokenizer_arg(line, start, end, TOKEN_STRING);
    add_arg_list(cmd, arg);
    return (end);
}

int blank_argument_tokenization(t_env *env, t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int start;
    int end;
    
    end = index;
    start = index;
    while (line[index])
    {
        if (!(is_blank_argument(env, line, index)))
        {
            end = index - 1;
            break;
        }
        index++;
    }
    arg = tokenizer_arg(line, start, end, TOKEN_BLANK);
    add_arg_list(cmd, arg);
    return (end);
}