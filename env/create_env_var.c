/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:00:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 08:13:52 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_chained_var(t_env *env, char **env_variable)
{	
	int		index;
	char	*name;
	char	*value;
	t_var	*var;

	index = 0;
	while (env_variable[index])
	{
		name = get_variable_name(env_variable[index]);
		value = get_env_variable_value(env_variable[index]);
		var = init_env_variable(name, value, VALUE);
		add_variables_list(env, var);
		index++;
	}
}

void	add_new_env_variable(t_env *env, t_var *new)
{
	t_var	*last_var;

	last_var = get_last_env_var(env);
	if (!last_var)
		return ;
	connect_new_var(last_var, new, NULL);
	new->index = last_var->index + 1;
}

char	**add_env_variable(char **variables, char *var)
{
	int		last_index;
	char	**new_variables;

	last_index = len_array(variables);
	new_variables = ft_arrayjoin_str(variables, var, last_index);
	return (new_variables);
}
