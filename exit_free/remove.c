/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:20:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 13:35:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all(t_env *env)
{   
    remove_all_token(env);
    remove_variable(env->variable);
    remove_all_line(env);
    env->variable = NULL;
    free(env->history);
    env->history = NULL;
    free(env);
}

void remove_all_line(t_env *env)
{
    t_line *line;
    t_line *iter;

    line = get_first_line(env);
    iter = line;
    if (!line)
        return ;
    while (iter)
    {
        iter = line->next;
        disconect_line(line);
        remove_line(line);
        line = iter;
    }
    env->first_line = NULL;
}

void remove_line(t_line *line)
{
    if (line->content)
        free(line->content);
    free(line);
}

void remove_variable(t_variable *vars)
{
    free_array(vars->bins);
    free_array(vars->variables);
    free_env_var_list(vars);
    free(vars);
}

void free_env_var_list(t_variable *variable)
{
    t_env_var *var;
    t_env_var *iter;

    var = get_first_env_var(variable);
    if (!var)
        return ;
    while (var)
    {
        iter = var->next;
        disconect_env_var(variable, var);
        remove_env_var(var);
        var = iter;
    }
    variable->first_var = NULL;
}

void remove_env_var(t_env_var *var)
{
    if (var->name)
        free(var->name);
    var->name = NULL;
    if (var->value)
        free(var->value);
    var->value = NULL;
    if (var)
        free(var);
    var = NULL; 
}
// void exit_shell(t_env *env)
// {
    
// }