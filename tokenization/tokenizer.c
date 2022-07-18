/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 16:50:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_token *tokenizer(char *line, int start, int end, int id)
{
    t_token *token;
    char *content;
    
    content = ft_substr(line, start, (end - start) + 1);
    token = create_token(content, id);
    return (token);
}

void tokenization(t_env *env, char *line)
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
        if (is_blank(line[index]))
        {
            new_index = blank_detection(line, index);
            token = tokenizer(line, index, new_index, TOKEN_BLANK);
            add_chained_list(env, token);
            
            index = new_index;
        }
        // if (is_double_quote(line[index]))
        // {
        //    new_index = double_quotes_detection(line, index);
        //    token = tokenizer(line, index, new_index, TOKEN_DOUBLE_QUOTE);
        //    add_chained_list(env, token);
           
        //    index = new_index;
        // }
        // if (is_single_quote(line[index]))
        // {
        //     new_index = single_quotes_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_SINGLE_QUOTE);
        //     add_chained_list(env, token);
            
        //     index = new_index;
        // }
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
        // if (is_redirection(line, index))
        // {
        //     new_index = redirection_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_REDIRECTION);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
        // if (is_boolean_operator(line, index))
        // {
        //     new_index = boolean_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_BOOLEAN);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
        // // printf("%d , [%c] : is variable -> %d\n", index, line[index], is_variable(line, index));
        // if (is_variable(line, index))
        // {
        //     new_index = variables_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_VARIABLE);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
        index++;
    }
    print_chained_list(env);
     
}