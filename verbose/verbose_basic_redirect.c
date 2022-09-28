/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_basic_redirect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:31:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:34:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_heredoc_info(t_redir *redir, t_cmd *prev_cmd)
{
	char	*prev_cmd_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | LIMITTER : [%s]\n", redir->limiter);
	printf(" ----------------\n");
}

void	print_input_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file)
{
	char	*prev_cmd_name;
	char	*next_file_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	if (next_file)
		next_file_name = next_file->name;
	else
		next_file_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | next_file : [%s]\n", next_file_name);
	printf(" | fd_file : [%d]\n", next_file->fd);
	printf(" ----------------\n");
}

void	print_output_chevron(t_redir *redir, t_cmd *prev_cmd,
							t_file *next_file)
{
	char	*prev_cmd_name;
	char	*next_file_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	if (next_file)
		next_file_name = next_file->name;
	else
		next_file_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | next_file : [%s]\n", next_file_name);
	printf(" | fd_file : [%d]\n", next_file->fd);
	printf(" ----------------\n");
}

void	print_append_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file)
{
	char	*prev_cmd_name;
	char	*next_file_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	if (next_file)
		next_file_name = next_file->name;
	else
		next_file_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | next_file : [%s]\n", next_file_name);
	printf(" | fd_file : [%d]\n", next_file->fd);
	printf(" ----------------\n");
}
