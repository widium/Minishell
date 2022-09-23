/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 16:55:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int argument_detection(t_env *env, t_cmd *cmd, char *line, int index)
{
    int new_index;

    new_index = index;
    if (is_flags(line, index))
    {
        new_index = flags_tokenization(env, cmd, line, index);
        index = new_index;
    }
    while (line_is_not_finish(line, index) && !(is_separator(line, index)))
    {
        new_index = argument_classification(env, cmd, line, index);
        index = new_index;
        index++;
    }
    return (new_index);
}

int argument_classification(t_env *env, t_cmd *cmd, char *line, int index)
{
    int new_index;
    char *name;
    
    new_index = index;
    if (is_blank_argument(env, line, index))
    {
        new_index = blank_argument_tokenization(env, cmd, line, index);
    }
    else if (is_single_quote(line[index]))
    {
        new_index = single_quotes_tokenization(cmd, line, index);
    } 
    else if (is_double_quote(line[index]))
    {
        new_index = double_quotes_tokenization(env, cmd, line, index);
    }  
    else if (is_variable_word(line, index))
    {
        new_index = variable_tokenization(env, cmd, line, index);
    }   
    else if (is_word(env, line, index))
    {
        new_index = word_argument_extraction(env, cmd, line, index);
    }
    return (new_index);
}

