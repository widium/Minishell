/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/19 19:01:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void parsing(t_env *env, char *line)
{
    int index;
    int new_index;
    int count;
    t_token *token;
    char *content;

    count = 0;
    index = 0;
    new_index = index;
    
    while (line[index])
    {
        // if (is_blank(line[index]))
        // {
        //     new_index = blank_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_BLANK);
        //     add_chained_list(env, token);
            
        //     index = new_index;
        // }
        if (is_double_quote(line[index]))
        {
           new_index = double_quotes_detection(line, index);
           token = tokenizer(line, index, new_index, TOKEN_DOUBLE_QUOTE);
           add_chained_list(env, token);
           
           index = new_index;
        }
        if (is_single_quote(line[index]))
        {
            new_index = single_quotes_detection(line, index);
            token = tokenizer(line, index, new_index, TOKEN_SINGLE_QUOTE);
            add_chained_list(env, token);
            
            index = new_index;
        }
        if (is_word(line, index))
        {
            new_index = word_detection(line, index);
            token = tokenizer(line, index, new_index, TOKEN_WORD);
            add_chained_list(env, token);

            index = new_index;
        }
        // if (is_paranthesis(line, index))
        // {
        //     new_index = paranthesis_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_PARANTHESIS);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
        if (is_redirection(line, index))
        {
            new_index = redirection_detection(line, index);
            token = tokenizer_redir(line, index, new_index, TOKEN_REDIRECTION);
            add_chained_list(env, token);

            index = new_index;
        }
        if (is_boolean_operator(line, index))
        {
            new_index = boolean_detection(line, index);
            token = tokenizer_bool(line, index, new_index, TOKEN_BOOLEAN);
            add_chained_list(env, token);

            index = new_index;
        }
        // // printf("%d , [%c] : is variable -> %d\n", index, line[index], is_variable(line, index));
        if (is_variable(line, index))
        {
            new_index = variables_detection(line, index);
            token = tokenizer_variable(line, index, new_index, TOKEN_VARIABLE);
            add_chained_list(env, token);

            index = new_index;
        }
        if (is_built_in_index(line, index))
        {
            new_index = word_detection(line, index);
            token = tokenizer_command(line, index, new_index, TOKEN_BUILT_IN);
            new_index = command_information(token, line, ++new_index);
            add_chained_list(env, token);
            
            index = new_index; 
        }
        index++;
    }
    print_chained_list(env);
     
}