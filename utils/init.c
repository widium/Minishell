/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/26 16:51:25 by ebennace         ###   ########.fr       */
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

t_env	*init_env(char **varaibles)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->variables = varaibles;
	env->error = init_err();
    env->history = NULL;
    env->line = NULL;
	env->first_token = NULL;
	env->nbr_cmd = 0;
	return (env);
}

