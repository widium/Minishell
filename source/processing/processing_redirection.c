/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:15:47 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	processing_redirection(t_env *env)
{
	t_token	*token;

	if (have_token_redirection(env))
	{
		token = get_first_token_redirection(env);
		while (token)
		{
			manage_fd_for_redirection(token);
			token = get_next_token_redirection(token);
		}
		if (env->verbose == 1)
		{
			ft_printf("=== Processing Redirection ===\n");
			print_all_redirect_info(env);
			ft_printf("-- Command Redirection --\n");
			print_all_cmd_info(env);
			ft_printf("=========\n");
		}
	}
}

void	change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out)
{
	cmd->fd_in = fd_in;
	cmd->fd_out = fd_out;
}

void	redirect_cmd(t_cmd *cmd)
{
	int	fd_in;
	int	fd_out;

	fd_in = cmd->fd_in;
	fd_out = cmd->fd_out;
	if (is_not_standard_fd(fd_in))
	{
		dup2(fd_in, STDIN_FILENO);
	}
	if (is_not_standard_fd(fd_out))
	{
		dup2(fd_out, STDOUT_FILENO);
	}
}
