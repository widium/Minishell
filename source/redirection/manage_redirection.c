/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:53:29 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:29:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	manage_fd_for_redirection(t_token *token)
{
	if (is_token_basic_redirection(token))
	{
		manage_fd_basic_redirection(token);
	}
	else if (is_token_pipe(token))
	{
		manage_fd_pipe(token);
	}
	else if (is_token_heredoc(token))
	{
		manage_fd_heredoc(token);
	}
}

void	manage_fd_heredoc(t_token *token)
{
	t_cmd	*prev_cmd;
	t_redir	*redir;
	char	*tmp_file_name;
	int		fd_tmp;

	redir = get_class(token);
	prev_cmd = get_prev_cmd(token);
	tmp_file_name = heredoc_prompt(redir->limiter);
	fd_tmp = open(tmp_file_name, O_RDONLY, 0777);
	redir->tmp_file = init_file(tmp_file_name, fd_tmp);
	if (prev_cmd)
	{
		change_fd_cmd(prev_cmd, fd_tmp, prev_cmd->fd_out);
	}
}

void	manage_fd_pipe(t_token *token)
{
	t_cmd	*prev_cmd;
	t_cmd	*next_cmd;
	int		fd[2];

	prev_cmd = get_prev_cmd(token);
	next_cmd = get_next_cmd(token);
	if (!next_cmd)
		return ;
	if (!prev_cmd)
		return ;
	pipe(fd);
	change_fd_cmd(prev_cmd, prev_cmd->fd_in, fd[1]);
	change_fd_cmd(next_cmd, fd[0], next_cmd->fd_out);
}

void	manage_fd_basic_redirection(t_token *token)
{
	t_cmd	*prev_cmd;
	t_file	*next_file;

	prev_cmd = get_prev_cmd(token);
	next_file = get_next_token_file(token);
	if (!prev_cmd)
		return ;
	if (is_token_input_chevron(token))
	{
		open_next_file_with_flags(token, next_file);
		change_fd_cmd(prev_cmd, next_file->fd, prev_cmd->fd_out);
	}
	else if (is_token_output_chevron(token))
	{
		open_next_file_with_flags(token, next_file);
		change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
	}
	else if (is_token_append_chevron(token))
	{
		open_next_file_with_flags(token, next_file);
		change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
	}
}

void	open_next_file_with_flags(t_token *token, t_file *file)
{
	if (is_token_input_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_RDONLY);
	}
	else if (is_token_output_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_TRUNC);
	}
	else if (is_token_append_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_APPEND);
	}
}
