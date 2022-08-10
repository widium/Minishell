/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/10 10:01:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int argument_detection(t_cmd *cmd, char *line, int index)
{
    int new_index;

    new_index = index;

    while (line[index] && !(is_separator(line, index)))
    {
        new_index = argument_classification(cmd, line, index);
        index = new_index;
        index++;
    }
    printf("after argument detection : %d\n", cmd_have_args(cmd));
    return (new_index);
}

int argument_classification(t_cmd *cmd, char *line, int index)
{
    int new_index;
    
    new_index = index;
    if (is_flags(line, index))
    {
        new_index = flags_extraction(cmd, line, index);
    }  
    else if (is_single_quote(line[index]))
    {
       new_index = single_quotes_extraction(cmd, line, index); 
    }  
    else if (is_double_quote(line[index]))
    {
        new_index = double_quotes_extraction(cmd, line, index);
    }    
    else if (is_variable(line, index))
    {
        new_index = variables_extraction(cmd, line, index);    
    } 
    else if (is_word(line, index))
    {
        new_index = word_argument_extraction(cmd, line, index);
    }
    return (new_index);
}

// void choose_arg_class(t_token *token, char *arg)
// {
//     // printf("[%s] is_single_quote -> %d\n", arg, is_single_quote(arg[0]));
//     // printf("[%s] is_double_quote -> %d\n", arg, is_double_quote(arg[0]));
//     // printf("[%s] is_variable -> %d\n", arg, is_variable(arg, 0));
//     if (is_single_quote(arg[0]))
//         ((t_cmd *)token->class)->id_arg = TOKEN_SINGLE_QUOTE;
//     else if (is_double_quote(arg[0]))
//         ((t_cmd *)token->class)->id_arg = TOKEN_DOUBLE_QUOTE;
//     else if (is_variable(arg, 0))
//         ((t_cmd *)token->class)->id_arg = TOKEN_VARIABLE;
//     else
//         ((t_cmd *)token->class)->id_arg = TOKEN_NULL;
// }