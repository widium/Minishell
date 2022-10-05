/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:23:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 09:59:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_file	*init_file(char *name, int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = name;
	file->fd = fd;
	return (file);
}

t_env	*init_env(char **env_variable)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->verbose = 0;
	env->error_parsing = 0;
	env->error_processing = 0;
	env->env_vars = NULL;
	env->first_var = NULL;
	env->first_line = NULL;
	env->first_token = NULL;
	create_chained_var(env, env_variable);
	add_signal_env_var(env);
	free_array(env_variable);
	g_env = env;
	return (env);
}

t_var	*init_env_variable(char *name, char *value, int id)
{
	t_var	*var;

	var = (t_var *)malloc(sizeof(t_var));
	if (!var)
		return (NULL);
	var->index = -1;
	var->id = id;
	var->name = name;
	var->value = value;
	var->next = NULL;
	var->prev = NULL;
	return (var);
}
