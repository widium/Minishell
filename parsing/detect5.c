/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:30:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 18:31:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void wildcard_detection(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if (line[i] == '*')
        {
            printf("WILDCARD : [%c]",line[i]);
            if (line[i-1] != ' ')
            {
                printf(" -> PREFIX : [");
                prefixe_wildcard_detection(line, i-1);
                printf("]");
            }
            if (line[i+1] != ' ')
            {
                printf(" -> SUFFIX : [");
                suffix_wildcard_detection(line, i+1);
                printf("]");
            }
            printf("\n");
        }      
        i++;
    }
    return ;
}

void prefixe_wildcard_detection(char *line, int i)
{
    while (line[i] && line[i] != ' ')
        i--;
    while (line[i] != '*')
    {
        printf("%c", line[i]);
        i++;
    }
}

void suffix_wildcard_detection(char *line, int i)
{
    while(line[i] && line[i] != ' ')
    {
        printf("%c", line[i]);
        i++;
    }
}