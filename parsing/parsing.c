/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 08:24:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void parsing(t_env *env, char *line)
{
    tokenization(env, line);
    if (env->verbose == 1)
        print_chained_list(env);
}

// void processing_old_path(t_env *env, t_cmd *cmd)
// {
    
// }

// if (is_paranthesis(line, index))
// {
//     new_index = paranthesis_detection(line, index);
//     token = tokenizer_word(line, index, new_index, TOKEN_PARANTHESIS);
//     add_token_list(env, token);

//     index = new_index;
// }