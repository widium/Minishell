/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:27:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/14 11:28:57 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_double_quote(char c)
{
    if (c == '\"')
        return (1);
    return (0);
}

int is_single_quote(char c)
{
    if (c == '\'')
        return (1);
    return (0);
}

int is_in_double_quote(char *line, int index)
{
    int first;
    int last;
    int backup;

    first = 0;
    last = 0;
    backup = index;
    while (line[index])
    {
        if (is_double_quote(line[index]))
        {
            first++;
            break;
        }
        index--;
    }
    index = backup;
    while (line[index])
    {
        if (is_double_quote(line[index]))
        {
            last++;
            break;
        }  
        index++;
    }
    if (first && last)
        return (1);
    return (0);
    
}

int is_in_single_quote(char *line, int index)
{
    int first;
    int last;
    int backup;

    first = 0;
    last = 0;
    backup = index;
    while (line[index])
    {
        if (is_single_quote(line[index]))
        {
            first++;
            break;
        }
        index--;
    }
    index = backup;
    while (line[index])
    {
        if (is_single_quote(line[index]))
        {
            last++;
            break;
        }  
        index++;
    }
    if (first && last)
        return (1);
    return (0);
    
}

int is_in_quote(char *line, int index)
{
    if (is_in_double_quote(line, index) || is_in_single_quote(line, index))
        return (1);
    return (0);
}