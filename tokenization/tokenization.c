/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:59:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/16 16:14:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void tokenization(t_env *env, char *line)
{
    int index;

    index = 0;
    while (line_is_not_finish(line, index))
    {
        if (is_word(env, line, index))
        { 
            index = word_classification(env, line, index);
        }
        else if (is_redirection(line, index))
        {
            index = redirection_classification(env, line, index);
        }
        if (is_boolean_operator(line, index))
        {
            index = boolean_classification(env, line, index);
        }
        index++;
    }
}

int variable_tokenization(t_env *env, t_cmd *cmd, char *line, int index)
{
    int new_index;
    
    if (is_variable(env, line, index))
        new_index = variables_extraction(env, cmd, line, index);
    else 
        new_index = word_detection(env, line, index);
    return (new_index);
}
