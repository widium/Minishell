/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:31:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/21 18:35:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void echo(t_cmd *cmd)
{
    if (!cmd->arg)
        return ;
    ft_putstr_fd(cmd->arg, cmd->fd_out);
    if (!(cmd_have_flags(cmd)))
        ft_putstr_fd("\n", cmd->fd_out);
}

void cd(t_cmd *cmd, t_env *env)
{
    char *path;
    char *new_path;

    if (!cmd->arg)
        return ;
    path = cmd->arg;
    if (chdir(path) == -1)
        perror("Error : ");
    new_path = get_current_path();
    change_env_var_value_with_name(env, "PWD", new_path);
}

void env_built_in(t_cmd *cmd, t_env *env)
{
    t_variable *vars;

    vars = env->variable;
    print_all_env_var(vars);
}

void export_built_in(t_cmd *cmd, t_env *env)
{
    t_env_var *var;
    char *name;
    char *value;
    int  id;
    
    if (!cmd->arg)
    {
        print_all_env_export_var(env->variable);
        return ;
    }
    name = get_variable_name(cmd->arg);
    value = get_env_variable_value(cmd->arg);
    if (!value)
        id = NONE_VALUE;
    else 
        id = VALUE;
    if (variable_exist(env, name))
    {
        change_env_var_value_with_name(env, name, value);
        free(name);
    }
    else
    {
        var = init_env_variable(name, value, id);
        add_new_env_variable(env->variable, var);
    }
}

void unset(t_cmd *cmd, t_env *env)
{
    t_env_var *var;
    char *name;

    if (!cmd->arg)
        return ;
    name = get_variable_name(cmd->arg);
    var = get_env_var_with_name(env->variable, name);
    remove_and_disconect_env_var(env->variable, var);
    free(name);
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