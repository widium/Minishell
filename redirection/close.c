/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:33:26 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 08:13:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all_fd(t_env *env)
{
	t_token	*token;

	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			close_fd_cmd(get_class(token));
		}
		else if (is_token_heredoc(token))
		{
			remove_tmp_file(token);
		}
		token = token->next;
	}
}

void	close_fd_cmd(t_cmd *cmd)
{
	if (is_not_standard_fd(cmd->fd_in))
	{
		close(cmd->fd_in);
	}
	if (is_not_standard_fd(cmd->fd_out))
	{
		close(cmd->fd_out);
	}
}

void	remove_tmp_file(t_token *token_heredoc)
{
	t_redir	*redir;
	t_file	*tmp_file;

	redir = get_class(token_heredoc);
	tmp_file = redir->tmp_file;
	unlink(tmp_file->name);
	free(tmp_file);
	redir->tmp_file = NULL;
}
