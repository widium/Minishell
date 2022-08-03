/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 12:38:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void execution(t_env *env)
{
    t_cmd *cmd;
    char **bins;

    cmd = get_first_cmd(env);
    bins = get_bins(env);
    if (is_cmd_bin(cmd))
    {
        setup_bin_path(cmd, bins);
        print_cmd_info(cmd);
        bin_execution(env, cmd);       
    }
    else if (is_cmd_built_in(cmd))
    {
        printf("c'est un built-in\n");
    }
}

void bin_execution(t_env *env, t_cmd *cmd)
{
    char *path;
    char **args;
    char **variables;

    path = cmd->bin;
    args = cmd->args;
    variables = env->variable->variables;
    execve(path, args, variables);
}

// void built_in_execution(t_env *env, t_cmd *cmd)
// {
    
// }