/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 14:52:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


char *double_quotes_detection(char *string)
{
    int start;
    int end;
    int len;

    start = 0;
    end = 0;
    
    while (string[start])
    {
        if (string[start] == '\"')
        {
            printf("DOUBLE_QUOTES : [\"");
            end = start+1;
            while (string[end] && string[end] != '\"')
            {
                printf("%c", string[end]);
                end++;
            }
            printf("\"]\n");
            start = end;
        }
        start++;
    }
    
    return (NULL);
    
}

char *single_quotes_detection(char *string)
{
    int start;
    int end;
    int len;

    start = 0;
    end = 0;
    
    while (string[start])
    {
        if (string[start] == '\'')
        {
            printf("SINGLE_QUOTES : [\'");
            end = start + 1;
            while (string[end] && string[end] != '\'')
            {
                printf("%c", string[end]);
                end++;
            }
            start = end;
            printf("\']\n");
        }
        start++;
    }
    return (NULL);
    
}