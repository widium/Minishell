/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 21:19:57 by ebennace         ###   ########.fr       */
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
        if (is_word(line, index))
        {
            new_index = word_detection(line, index);
            content = ft_substr(line, index, (new_index - index) + 1);
            if (is_cmd(content))
            {
                if (is_bin(content))
                {
                    token = tokenizer_command(content, TOKEN_BINARY);
                    new_index = command_information((t_cmd *)token->class, line, ++new_index);
                }
                else if (is_built_in(content))
                {
                    token = tokenizer_command(content, TOKEN_BUILT_IN);
                    new_index = command_information((t_cmd *)token->class, line, ++new_index);
                } 
            }
            else if (is_file(line, index))
            {
                printf("[%d][%c] Result : is_after_redirect %d\n",index, line[index], is_after_redirect(line, index));
                printf("[%d][%c] Result : is_file %d\n",index, line[index], is_file(line, index));
                token = tokenizer_file(content, TOKEN_FILE);
            }
            else
            {
                token = tokenizer(line, index, new_index, TOKEN_WORD);
            }
            add_chained_list(env, token);
            index = new_index;
        }
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
        // if (is_paranthesis(line, index))
        // {
        //     new_index = paranthesis_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_PARANTHESIS);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
        index++;
    }
    print_chained_list(env);
    
     
}