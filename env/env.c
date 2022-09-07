/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:44:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/07 11:54:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void change_variable_value(t_env *env, char *var, char *value)
{
    int i;
    char **variables;
    char *new_var;
    int index_var;
    
    i = 0;
    variables = get_env_variables(env);
    index_var = get_variable_index(env->variable->variables, var);
    free(variables[index_var]);
    variables[index_var] = ft_strjoin_char(var, value, '=');
}