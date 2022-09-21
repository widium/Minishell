/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:44:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/21 17:27:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void change_env_var_value_with_name(t_env *env, char *name, char *value)
{
    t_env_var *var;

    var = get_env_var_with_name(env->variable, name);
    if (!var)
        return ;
    change_env_var_value(var, value);
}

void change_env_var_value(t_env_var *var, char *new_value)
{
    if (var->value)
        free(var->value);
    var->value = new_value;
    var->id = VALUE;
}