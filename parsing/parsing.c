/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:37:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void parsing(t_env *env, char *line)
{
    int index;

    index = 0;
    while (line[index])
    {
        index = tokenization(env, line, index);
        index++;
    }
    // change_variable_token(env);
    // concatenate_args(env);
    
    print_chained_list(env);
    remove_all(env);
    // exit(0);
}

// if (is_paranthesis(line, index))
        // {
        //     new_index = paranthesis_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_PARANTHESIS);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }