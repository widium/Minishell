/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 13:56:08 by ebennace         ###   ########.fr       */
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

t_env	*init_env(void)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->error = init_err();
    env->history = init_file();
	env->first_cmd = NULL;
    env->line = NULL;
	env->first_token = NULL;
	env->nbr_cmd = 0;
	return (env);
}

