/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/12 17:23:50 by ebennace         ###   ########.fr       */
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
	recover_path_variable(var, env_variable);
	return (var);
}

