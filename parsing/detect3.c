/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/11 14:04:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int variables_detection(char *line, int index)
{
    int start;

    start = index;
    while (line[index])
    {
        if (is_blank(line[index]) || is_variable(line, index))
            return (index - 1);
        index++;
    }
    return (start);
}

void redirection_detection(char *str)
{
    int start;
    int end;

    start = 0;
    end = 0;
    while (str[start])
    {
        if (is_redirection(str, start))
        {
            printf("REDIRECTION : [");
            end = start;
            while (str[end] && str[end] != ' ')
            {
               printf("%c", str[end]);
               end++; 
            }
            start = end;
            printf("]\n");
        }
        start++;
    }
}

void boolean_detection(char *str)
{
    int start;
    int end;

    start = 0;
    while (str[start])
    {
        if (is_boolean_operator(str, start))
        {
            printf("BOOLEAN : [");
            end = start;
            while (str[end] && str[end] != ' ')
            {
                printf("%c", str[end]);
                end++;
            }
            start = end;
            printf("]\n");
        }
        start++;
    }
}