/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/08 19:05:00 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void tokenizer(char *line)
{
    int index;
    int new_index;
    int token;

    index = 0;
    new_index = index;
    new_index = double_quotes_detection(line, index);
    
    // print_str_index(line, new_index);
    while (line[index])
    {
        if (is_blank(line[index]))
        {
            new_index = blank_detection(line, index);
            token = SPACE;
            tokenization(line, index, new_index, token);
        }
        index = new_index;
        // if (is_double_quote(line[index]))
        // {
        //    new_index = double_quotes_detection(line, index);
        //    token = DOUBLE_QUOTE;
        //    tokenization(line, index, new_index, token);
        //    index++;
        // //    break; 
        // }
        index++;
    }
    // print_detection(line, index, new_index, token);
     
}

void tokenization(char *line, int start, int end, int token)
{
    printf("token : [");
    while (line[start] && start <= end)
    {
        printf("%c", line[start]);
        start++;
    }
    printf("], id : [%d]\n", token);
    
}