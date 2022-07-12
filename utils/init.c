/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/12 15:05:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_cmd   *init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
        return (NULL);
	cmd->brut = NULL;
	cmd->bin = NULL;
	cmd->flags = NULL;
	cmd->complete = NULL;
	cmd->next_cmd = NULL;
	cmd->index = 0;
	return (cmd);
}

t_file	*init_file(void)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = NULL;
	file->fd = -1;
	return (file);
}

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

