/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:13:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 19:39:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


int flags_detection(char *line, int index)
{
    while (line[index] && !(is_blank(line[index])) && !(is_separator(line, index)))
	    index++;
    return (index-1);
}

int arguments_detection(char *line, int index)
{
    while (line[index] && !(is_separator(line, index)) && !(is_paranthesis(line, index)))
	    index++;
    index--;
    if (is_blank(line[index]))
	    index--;
    return (index);
}

int command_information(t_cmd *cmd, char *line, int index)
{
    t_arg *arg;
    int new_index;

    new_index = index;
    
    while (line[index] && !(is_separator(line, index)))
    {
        if (is_flags(line, index))
        {
            new_index = flags_detection(line, index);
            arg = tokenizer_arg(line, index, new_index, TOKEN_FLAGS);
            add_arg_list(cmd, arg);
            
            index = new_index;
        }
        else if (is_single_quote(line[index]))
        {
            new_index = single_quotes_detection(line, index);
            arg = tokenizer_arg(line, index, new_index, TOKEN_SINGLE_QUOTE);
            add_arg_list(cmd, arg);
            
            index = new_index;
        }
        else if (is_double_quote(line[index]))
        {
            new_index = double_quotes_detection(line, index);
            arg = tokenizer_arg(line, index, new_index, TOKEN_DOUBLE_QUOTE);
            add_arg_list(cmd, arg);
            
            index = new_index;
        }
        else if (is_variable(line, index))
        {
            new_index = variables_detection(line, index);
            arg = tokenizer_arg(line, index, new_index, TOKEN_VARIABLE);
            add_arg_list(cmd, arg);
            
            index = new_index;
        }
        else if (is_word(line, index))
        {
            new_index = word_detection(line, index);
            arg = tokenizer_arg(line, index, new_index, TOKEN_WORD);
            add_arg_list(cmd, arg);
            
            index = new_index; 
        }
        index++;
    }
    // while (line[index] && !(is_separator(line, index)))
    // {
    //     if (line[index] == '-')
    //     {
    //         new_index = flags_extraction(token, line, index);	
    //         new_index++;
    //         break;
    //     }
    //     index++;
    // }
    // index = new_index;
    // while (line[index] && !(is_separator(line, index)))
    // {
    //     if (is_double_quote(line[index]))
    //     {
    //        new_index = double_quotes_detection(line, index);
    //        index = new_index;
    //     }
    //     if (is_single_quote(line[index]))
    //     {
    //         new_index = single_quotes_detection(line, index);
    //         index = new_index;
    //     }
    //     if (is_argument(line, index))
    //     {
    //         new_index = argument_extraction(token, line, index);
    //         if (is_blank(line[index]))
    //             new_index++;
    //         break;
    //     }
    //     index++;
    // }
    return (new_index);
}

int flags_extraction(t_token *token, char *line, int index)
{
    int new_index;
    char *flags;

    flags = NULL;
    new_index = flags_detection(line, index);
    flags = ft_substr(line, index, (new_index - index) + 1);
    ((t_cmd *)token->class)->flags = flags;
    return (new_index);  
}

int argument_extraction(t_token *token, char *line, int index)
{
    int new_index;
    char *arg;

    arg = NULL;
    new_index = arguments_detection(line, index);
    arg = ft_substr(line, index, (new_index - index) + 1);
    choose_arg_class(token, arg);
    ((t_cmd *)token->class)->arg = arg;
    return (new_index);       
}

void choose_arg_class(t_token *token, char *arg)
{
    // printf("[%s] is_single_quote -> %d\n", arg, is_single_quote(arg[0]));
    // printf("[%s] is_double_quote -> %d\n", arg, is_double_quote(arg[0]));
    // printf("[%s] is_variable -> %d\n", arg, is_variable(arg, 0));
    if (is_single_quote(arg[0]))
        ((t_cmd *)token->class)->id_arg = TOKEN_SINGLE_QUOTE;
    else if (is_double_quote(arg[0]))
        ((t_cmd *)token->class)->id_arg = TOKEN_DOUBLE_QUOTE;
    else if (is_variable(arg, 0))
        ((t_cmd *)token->class)->id_arg = TOKEN_VARIABLE;
    else
        ((t_cmd *)token->class)->id_arg = TOKEN_NULL;
}