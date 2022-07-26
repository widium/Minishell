/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:59:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/26 18:01:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int tokenization(t_env *env, char *line, int index)
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
    return (index);
}