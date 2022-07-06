/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/06 17:57:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

// void    parsing(char *line)
// {
//     int i;
//     int space;
//     int cote;
//     int string;

//     i = 0;
//     space = 0;
//     cote = 0;
//     string = 0;
    
//     while (line[i])
//     {
//         if (line[i] == ' ')
//             space++;
//         if (line[i] == '\"')
//             cote++;
//         if (line[i] == '\'')
//             string++;
//         i++;
//     }

//     printf("space : %d\n", space);
//     printf("cote : %d\n", cote);
//     printf("string : %d\n", string);
// }

// char *double_quotes_detection(char *string)
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
//             start++;
//             end = start;
//             while (string[end])
//             {
//                 if (string[end] == '\"')
//                 {
//                     len = end - start;
//                     return (ft_substr(string, start, len));
//                 }
//                 end++;
//             }
//             printf("Pas de 2e occurence...\n");
//         }
//         start++;
//     }
//     return (NULL);
    
// }

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

void word_detection(char *str)
{
    int i;
    int y;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ' || i == 0)
        {
            printf("WORD : [");
            if (i > 0)
                y = i+1;
            else
                y = i;
            while (str[y] && str[y] != ' ')
            {
               printf("%c", str[y]);
               y++; 
            }
            printf("],");
        }
        i++;
    }
    printf("\n");
}

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

void wildcard_detection(char *str)
{
    int start;
    
    start = 0;
    while (str[start])
    {
        if (str[start] == '*')
            printf("WILDCARD : [%c]\n",str[start]);
        start++;
    }
}

void heredoc_detection(char *str)
{
    int start;
    int end;

    start = 0;
    end = 0;
    while (str[start])
    {
        if (is_doublons(str, start, '<'))
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


// void file_detection(char *str)
// {
    
// }