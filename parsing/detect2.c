/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/08 19:01:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


// int double_quotes_detection(char *string, int i)
// {
//     int start;
//     int end;
//     int len;

//     start = 0;
//     end = 0;
    
//     while (string[start])
//     {
//         if (string[start] == '\"')
//         {
//             printf("DOUBLE_QUOTES : [\"");
//             end = start+1;
//             while (string[end] && string[end] != '\"')
//             {
//                 printf("%c", string[end]);
//                 end++;
//             }
//             printf("\"]\n");
//             start = end;
//         }
//         start++;
//     }
    
//     return (NULL);
// }

int double_quotes_detection(char *string, int index)
{
    int start;
    int len;

    start = index;
    
    index++;
    while (string[index])
    {
        if (is_back_slash(string[index]))
        {
            index++;
            if (is_double_quote(string[index]))
                index++;
        }
        if (is_double_quote(string[index]))
            return (index);
        index++;
    }
    return (start);
    
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


int blank_detection(char *line, int index)
{
    while (line[index] && is_blank(line[index]))
        index++;
    return (index);
}