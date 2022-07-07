/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 18:31:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void variables_detection(char *str)
{
    int start;
    int end;

    start = 0;
    end = 0;
    while (str[start])
    {
        if (str[start] == '$')
        {
            printf("VARIABLE : [");
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