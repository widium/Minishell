/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/11 13:23:11 by ebennace         ###   ########.fr       */
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


int blank_detection(char *line, int index)
{
    while (line[index] && is_blank(line[index]))
        index++;
    return (index - 1);
}