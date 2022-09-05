/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:31:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 15:03:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void echo(t_cmd *cmd)
{
    ft_putstr_fd(cmd->arg, cmd->fd_out);
}

// void cd(char **variables, char *args)
// {
//     chdir();
// }

void env_built_in(t_cmd *cmd, t_env *env)
{
    env->variable->variables;
    
}

// void export_built_in(char **variables, char *args)
// {
//     void;
// ft_arrayjoin_str()
// }

// void unset(char **variables, char *args)
// {
// ft_arrayremove_str()
// }

// void exit_built_in(int exit)
// {
//     void;
// }