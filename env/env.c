/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:44:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/13 15:57:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void change_variable_value(t_env *env, char *var, char *value)
{
    char **variables;
    int index_var;
    
    variables = get_env_variables(env);
    index_var = get_variable_index(env->variable->variables, var);
    free(variables[index_var]);
    variables[index_var] = ft_strjoin_char(var, value, '=');
}