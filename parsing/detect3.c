/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/14 21:32:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int variables_detection(char *line, int index)
{
    int start;

    start = index;
    if (line[index + 1] == '$')
        return (index + 1);
    index++;
    while (line[index])
    {
        if (is_blank(line[index]))
        {
           return (index - 1);
        } 
        index++;
    }
    return (index);
    // return (start);
}

int boolean_detection(char *line, int index)
{
    int start;
    
    start = index;
    while (line[index])
    {
        if (!(is_boolean_operator(line, index)))
            return (index - 1);
        index++;
    }
    return (start);
}

int redirection_detection(char *line, int index)
{
    int start;
    
    start = index;
    while (line[index])
    {
        if (!(is_redirection(line, index)))
            return (index - 1); 
        index++;
    }
    return (start);
}