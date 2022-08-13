/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/13 16:24:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void parsing(t_env *env, char *line)
{
    tokenization(env, line);
    if (env->verbose == 1)
        print_chained_list(env);
    check_error_parsing(env);
}

void processing_cmd_args(t_env *env)
{
    get_arg_variables_value(env);
    concatenate_args(env);
    print_cmd_info(get_first_cmd(env));
}

// if (is_paranthesis(line, index))
// {
//     new_index = paranthesis_detection(line, index);
//     token = tokenizer_word(line, index, new_index, TOKEN_PARANTHESIS);
//     add_chained_list(env, token);

//     index = new_index;
// }