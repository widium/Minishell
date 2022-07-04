/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/04 17:08:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    parsing(char *line)
{
    int i;
    int space;
    int cote;
    int string;

    i = 0;
    space = 0;
    cote = 0;
    string = 0;
    
    while (line[i])
    {
        if (line[i] == ' ')
            space++;
        if (line[i] == '\"')
            cote++;
        if (line[i] == '\'')
            string++;
        i++;
    }

    printf("space : %d\n", space);
    printf("cote : %d\n", cote);
    printf("string : %d\n", string);
}

char *double_quotes_extraction(char *string)
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
            start++;
            end = start;
            while (string[end])
            {
                if (string[end] == '\"')
                {
                    len = end - start;
                    return (ft_substr(string, start, len));
                }
                end++;
            }
            printf("Pas de 2e occurence...\n");
        }
        start++;
    }
    return (NULL);
    
}

char *single_quotes_extraction(char *string)
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
            start++;
            end = start;
            while (string[end])
            {
                if (string[end] == '\'')
                {
                    len = end - start;
                    return (ft_substr(string, start, len));
                }
                end++;
            }
            printf("Pas de 2e occurence...\n");
        }
        start++;
    }
    return (NULL);
    
}

// void quotes_extraction(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
        
//     }
// }

void word_extraction(char *str)
{
    int i;
    int y;

    i = 0;
    while (str[i])
    {
        
        if (str[i] == ' ')
        {
            printf("\"");
            y = i+1;
            while (str[y] != ' ')
            {
               printf("%c", str[y]);
               y++; 
            }
            printf("\",");
        }
        i++;
    }
}
