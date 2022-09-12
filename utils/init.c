/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/11 15:47:42 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_env	*init_env(char **env_variable)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->verbose = 0;
	env->error_parsing = 0;
	env->error_processing = 0;
	env->variable = init_variable(env_variable);
    env->history = NULL;
	env->first_token = NULL;
	return (env);
}

t_variable	*init_variable(char **env_variable)
{
	t_variable	*var;

	var = (t_variable *)malloc(sizeof(t_variable));
	if (!var)
		return (NULL);
	recover_path_and_bins_variable(var, env_variable);
	var->variables = add_env_variable(env_variable, "?=0");
	free_array(env_variable);
	return (var);
}

char **add_env_variable(char **variables, char *var)
{
	int	last_index;
	char **new_variables;
	
	last_index = ft_strlen_array(variables);
	new_variables = ft_arrayjoin_str(variables, var, last_index);
	return (new_variables);
}

