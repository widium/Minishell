/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:39:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error_token_redirection(t_token *token)
{
	t_redir	*redir;
	int		result;

	result = 0;
	redir = get_class(token);
	if (is_token_basic_redirection(token))
	{
		result = check_error_token_basic_redirection(token, redir);
	}
	else if (is_token_heredoc(token))
	{
		result = check_error_token_heredoc(redir);
	}
	else if (is_token_pipe(token))
	{
		result = check_error_token_pipe(token, redir);
	}
	return (result);
}

int	check_error_token_heredoc(t_redir *redir)
{
	if (!redir->limiter)
	{
		ft_printf("Error : [limiter after \"%s\" not found]\n", redir->content);
		return (1);
	}
	return (0);
}

int	check_error_token_basic_redirection(t_token *token, t_redir *redir)
{
	if (!(is_token_file(token->next)) || !token->next)
	{
		ft_printf("Error : [next_file after \"%s\" not found]\n", redir->content);
		return (1);
	}
	return (0);
}

int	check_error_token_pipe(t_token *token, t_redir *redir)
{
	if (!(is_token_cmd(token->next)) || !token->next)
	{
		ft_printf("Error : [next_cmd after \"%s\" not found]\n", redir->content);
		return (1);
	}
	else if (!(is_token_cmd(token->prev)) || !token->prev)
	{
		ft_printf("Error : [prev_cmd before \"%s\" not found]\n", redir->content);
		return (1);
	}
	return (0);
}
