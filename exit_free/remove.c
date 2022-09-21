/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:20:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/21 15:52:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all(t_env *env)
{
    remove_all_token(env);
    remove_variable(env->variable);
    free(env->history);
    free(env);
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