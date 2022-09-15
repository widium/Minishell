/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:31:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/15 15:36:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo(t_cmd *cmd)
{
    ft_putstr_fd(cmd->arg, cmd->fd_out);
    if (!(cmd_have_flags(cmd)))
        ft_putstr_fd("\n", cmd->fd_out);
}

void cd(t_cmd *cmd, t_env *env)
{
    char *path;
    char *new_path;

    path = cmd->arg;
    if (chdir(path) == -1)
        perror("Error : ");
    new_path = get_current_path();
    change_variable_value(env, "PWD", new_path);
    free(new_path);
    
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
    free(variables);
    env->variable->variables = new_variables;
}

void unset(t_cmd *cmd, t_env *env)
{
    char **variables;
    char **new_variables;
    int index_var;

    variables = env->variable->variables;
    index_var = get_variable_index(variables, cmd->arg);
    new_variables = ft_arrayremove_str(variables, index_var);
    free(variables);
    env->variable->variables = new_variables;
}

void pwd(t_cmd *cmd, t_env *env)
{
    char *path;
    
    path = get_current_path();
    ft_putstr_fd(path, cmd->fd_out);
    ft_putstr_fd("\n", cmd->fd_out);
    free(path);
}

void exit_built_in(t_cmd *cmd, t_env *env)
{
    remove_all(env);
    ft_putstr_fd("exit", 2);
    ft_putstr_fd("\n", 2);
    exit(0);
}