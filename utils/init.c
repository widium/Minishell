/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:42:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


t_err *init_err(void)
{
	t_err	*error;

	error = (t_err *)malloc(sizeof(t_err));
	if (!error)
		return (NULL);
	error->exit = -1;
	return (error);
}

t_env	*init_env(char **env_variable)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->line = NULL;
	env->variable = init_variable(env_variable);
	env->error = init_err();
    env->history = NULL;
	env->first_token = NULL;
	env->nbr_cmd = 0;
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

