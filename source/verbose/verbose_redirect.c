/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:33:09 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:34:31 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_redirect_info(t_env *env)
{
	t_token	*token;
	t_redir	*redir;

	token = get_first_token_redirection(env);
	while (token)
	{
		if (is_token_redirection(token))
		{
			redir = get_class(token);
			print_redirect(token, get_prev_cmd(token),
				get_next_cmd(token), get_next_token_file(token));
		}
		token = get_next_token_redirection(token);
	}
}

void	print_redirect(t_token *token, t_cmd *prev_cmd,
						t_cmd *next_cmd, t_file *next_file)
{
	t_redir	*redir;

	redir = get_class(token);
	printf("___[TOKEN_REDIRECTION]___\n");
	if (is_token_pipe(token))
		print_pipe_info(redir, prev_cmd, next_cmd);
	else if (is_token_heredoc(token))
		print_heredoc_info(redir, prev_cmd);
	else if (is_token_input_chevron(token))
		print_input_chevron(redir, prev_cmd, next_file);
	else if (is_token_output_chevron(token))
		print_output_chevron(redir, prev_cmd, next_file);
	else if (is_token_append_chevron(token))
		print_append_chevron(redir, prev_cmd, next_file);
}

void	print_pipe_info(t_redir *redir, t_cmd *prev_cmd, t_cmd *next_cmd)
{
	char	*prev_cmd_name;
	char	*next_cmd_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	if (next_cmd)
		next_cmd_name = next_cmd->content;
	else
		next_cmd_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | cmd_out : [%s]\n", next_cmd_name);
	printf(" | fd_out : [%d]\n", redir->fd_out);
	printf(" ----------------\n");
}
