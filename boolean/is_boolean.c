/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_boolean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:10:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/21 17:31:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


int is_and_operator(char *line, int i)
{
    if (line[i] == '&' && line[i + 1] == '&')
        return (1);
    return (0);
}

int is_or_operator(char *line, int i)
{
   if (line[i] == '|' && line[i + 1] == '|')
        return (1);
    return (0); 
}

int is_boolean_operator(char *line, int i)
{
    if (is_or_operator(line, i) || is_and_operator(line, i))
        return (1);
    return (0);
}
