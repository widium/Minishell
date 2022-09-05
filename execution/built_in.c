/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:31:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 19:08:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo(t_cmd *cmd)
{
    ft_putstr_fd(cmd->arg, cmd->fd_out);
    if (!(cmd_have_flags(cmd)))
        ft_putstr_fd("\n", cmd->fd_out);
}

void cd(t_cmd *cmd)
{
    char *path;

    path = cmd->arg;
    if (chdir(path) == -1)
        perror("Error : ");
}

void env_built_in(t_cmd *cmd, t_env *env)
{
    char **variables;

    variables = env->variable->variables;
    print_array_fd(variables, cmd->fd_out);
}

void export_built_in(t_cmd *cmd, t_env *env)
{
    char **variables;
    char **new_variables;

    variables = env->variable->variables;
    new_variables = ft_arrayjoin_str(variables, cmd->arg, ft_strlen_array(variables));
    printf("len OLD : [%d]\n", ft_strlen_array(variables));
    printf("len NEW : [%d]\n", ft_strlen_array(new_variables));
    print_array_fd(variables, cmd->fd_out);
}

// void unset(char **variables, char *args)
// {
// ft_arrayremove_str()
// }

// void exit_built_in(int exit)
// {
//     void;
// }