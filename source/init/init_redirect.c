/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:54 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:25:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_redir	*init_redirection(int type, char *content)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = NULL;
	redir->content = content;
	redir->tmp_file = NULL;
	return (redir);
}

t_redir	*init_heredoc(int type, char *content, char *limiter)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = limiter;
	redir->content = content;
	return (redir);
}
