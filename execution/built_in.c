/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:31:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 17:59:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int echo(t_cmd *cmd)
{
    if (!cmd->arg)
        return (0);
    ft_putstr_fd(cmd->arg, cmd->fd_out);
    if (!(cmd_have_flags(cmd)))
        ft_putstr_fd("\n", cmd->fd_out);
    return (0);
}

int cd(t_cmd *cmd, t_env *env)
{
    char *path;
    char *new_path;
    char *last_path;

    if (!cmd->arg)
        return (0);
    path = cmd->arg;
    if (chdir(path) == -1)
    {
        ft_printf("%s: No such file or directory\n", path);
        return (1);
    }
    new_path = get_current_path();
    last_path = get_last_path(env);
    change_env_var_value_with_name(env, "PWD", new_path);
    change_env_var_value_with_name(env, "OLDPWD", last_path);
    return (0);
}

int env_built_in(t_cmd *cmd, t_env *env)
{
    print_all_env_var(env);
    return (0);
}

int export_built_in(t_cmd *cmd, t_env *env)
{
    char *name;
    char *value;
    int  id;
    
    if (!cmd->arg)
    {
        print_all_env_export_var(env);
        return (0);
    }
    name = get_export_variable_name(cmd->arg);
    if (!name)
    {
        ft_putstr_fd("export: not a valid identifier\n", 1);
        return (1);
    }
    value = get_export_variable_value(cmd->arg);
    id = assign_env_var_id(value);
    add_or_create_env_var(env, name, value, id);
    return (0);
}

void add_or_create_env_var(t_env *env, char *name, char *value, int id)
{
    t_env_var *var;
    
   if (variable_exist(env, name))
    {
        change_env_var_value_with_name(env, name, value);
        free(name);
    }
    else
    {
        var = init_env_variable(name, value, id);
        add_new_env_variable(env, var);
    } 
}

int assign_env_var_id(char *value)
{
    if (!value)
        return (NONE_VALUE);  
    return (VALUE);
}

int unset(t_cmd *cmd, t_env *env)
{
    t_env_var *var;
    char *name;

    if (!cmd->arg)
        return (0);
    name = get_variable_name(cmd->arg);
    var = get_env_var_with_name(env, name);
    if (var)
    {
        remove_and_disconect_env_var(env, var);
    }    
    free(name);
    return (0);
}

int pwd(t_cmd *cmd, t_env *env)
{
    char *path;
    
    path = get_current_path();
    ft_putstr_fd(path, cmd->fd_out);
    ft_putstr_fd("\n", cmd->fd_out);
    free(path);
    return (0);
}

void exit_built_in(t_cmd *cmd, t_env *env)
{
    remove_all(env);
    ft_putstr_fd("exit", 2);
    ft_putstr_fd("\n", 2);
    exit(0);
}