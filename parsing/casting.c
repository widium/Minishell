/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:32:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:30:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void *get_class(t_token *token)
{
    if (is_token_cmd(token))
    {
        return ((t_cmd *)token->class);
    }
    else if (is_token_redirection(token))
    {
        return ((t_redirection *)token->class);
    }
    else if (is_token_boolean(token))
    {
        return ((t_boolean *)token->class);
    }
    else if (is_token_file(token))
    {
        return ((t_file *)token->class);
    }
    return (NULL);
}


// void convert_void(void *ptr)
// {
//     return ((void **)ptr)
// }


