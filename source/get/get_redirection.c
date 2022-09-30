/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:43:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 11:54:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*get_first_token_redirection(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_redirection(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_redirection(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_redirection(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

int	get_nbr_pipes(t_env *env)
{
	t_token	*token;
	int		count;

	if (!(get_first_token(env)))
		return (0);
	count = 0;
	token = get_first_token(env);
	while (token)
	{
		if (is_token_pipe(token))
			count++;
		token = token->next;
	}
	return (count);
}

t_redir	*get_first_redirection(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_redirection(token))
			return (get_class(token));
		token = token->next;
	}
	return (NULL);
}
