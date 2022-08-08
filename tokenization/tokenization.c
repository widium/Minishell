/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:59:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 10:31:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void tokenization(t_env *env, char *line)
{
    int index;

    index = 0;
    while (line[index])
    {
        if (is_word(line, index))
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