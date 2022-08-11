/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/11 15:58:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void execution(t_env *env)
{
    t_cmd *cmd;
    t_token *token;
    char **bins;

    bins = get_bins(env);
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        if (is_cmd_bin(cmd))
        {
            setup_bin_path(cmd, bins);
            setup_bin_args(cmd, bins);
            // print_cmd_info(cmd);
            bin_execution(env, cmd);
        }
        else if (is_cmd_built_in(cmd))
        {
            printf("c'est un built-in\n");
        }
        token = get_next_token_cmd(token);
    }
}