/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/23 19:27:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int double_quotes_detection(char *line, int index)
{
    int start;

    start = index;
    index++;
    while (line[index])
    {
        while (line[index] && is_back_slash(line[index]))
            index++;
        if (is_double_quote(line[index]))
            return (index);
        index++;
    }
    return (start);
}

int single_quotes_detection(char *line, int index)
{
    int start;

    start = index;
    index++;
    while (line[start])
    {
        while (line[index] && is_back_slash(line[index]))
            index++;
        if (is_single_quote(line[index]))
            return (index);
        index++;
    }
    return (start);
}

int word_detection(char *line, int index)
{
    int start;

    start = index;
    while (line[index])
    {
        if (is_delimiter(line, index))
        {
            return (index - 1);
        }
        if (is_double_quote(line[index]))
        {
            index = double_quotes_detection(line, index);
        }
        if (is_single_quote(line[index]))
        {
            index = single_quotes_detection(line, index);
        }
        index++;
    }
    return (index);
}

int blank_detection(char *line, int index)
{
    while (line[index] && is_blank(line[index]))
        index++;
    return (index - 1);
}

int paranthesis_detection(char *line, int index)
{
    return (index);
}