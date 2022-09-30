/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:58:18 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 15:53:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_token_cmd(t_cmd *cmd)
{
	if (cmd->flags)
		free(cmd->flags);
	cmd->flags = NULL;
	if (cmd->bin)
		free(cmd->bin);
	cmd->bin = NULL;
	if (cmd->arg)
		free(cmd->arg);
	cmd->arg = NULL;
	if (cmd->args)
		free_array(cmd->args);
	cmd->args = NULL;
	if (cmd->content)
		free(cmd->content);
	cmd->content = NULL;
	remove_all_arg(cmd);
	if (cmd)
		free(cmd);
	cmd = NULL;
}

void	remove_token_redir(t_redir *redir)
{
	if (redir->content)
		free(redir->content);
	if (redir->limiter)
		free(redir->limiter);
	if (redir)
		free(redir);
}

void	remove_token_file(t_file *file)
{
	if (file->name)
		free(file->name);
	if (file)
		free(file);
}

void	remove_token_word(t_word *word)
{
	if (word->content)
		free(word->content);
	if (word)
		free(word);
}

void	remove_and_disconect_env_var(t_env *env, t_var *var)
{
	t_var	*iter;

	iter = get_first_env_var(env);
	if (!iter)
		return ;
	while (iter)
	{
		if (iter->index == var->index)
		{
			disconect_env_var(env, var);
			free_env_var(var);
			return ;
		}
		iter = iter->next;
	}
}
