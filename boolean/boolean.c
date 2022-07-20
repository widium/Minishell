/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:21:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/20 17:50:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int type_of_boolean(char *content)
{
    if (is_and_operator(content, 0))
        return (TOKEN_AND);
    else if (is_or_operator(content, 0))
        return (TOKEN_OR);
    return (TOKEN_NULL);
}