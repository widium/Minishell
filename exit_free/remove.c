/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:20:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 15:08:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all(t_env *env)
{   
    remove_all_token(env);
    free_env_var_list(env);
    remove_all_line(env);
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

void free_env_var_list(t_env *  env)
{
    t_env_var *var;
    t_env_var *iter;

    var = get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        iter = var->next;
        disconect_env_var(env, var);
        remove_env_var(var);
        var = iter;
    }
    env->first_var = NULL;
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