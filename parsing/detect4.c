/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:53:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 17:39:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void heredoc_detection(char *str)
{
    int start;
    int end;

    start = 0;
    end = 0;
    while (str[start])
    {
        if (is_heredoc(str, start))
        {
            printf("HERE_DOC : [");
            end = start;
            while (str[end] && str[end] != ' ')
            {
                printf("%c",str[end]); 
                end++; 
            }
            start = end;
            printf("]");
            recover_keyword(str, start);
        }
        start++;
    }
    
}

void recover_keyword(char *str, int i)
{
    i++;
    printf(" --> KEYWORD : [");
    while (str[i] && str[i] != ' ')
    {
        printf("%c", str[i]);
        i++;
    }
    printf("]\n");
}