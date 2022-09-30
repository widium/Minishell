/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:41:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 14:03:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*get_first_token_cmd(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_first_token_built_in(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_built_in(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_first_token_bin(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_bin(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_cmd	*get_prev_cmd(t_token *token)
{
	while (token)
	{
		if (is_token_cmd(token))
			return (get_class(token));
		token = token->prev;
	}
	return (NULL);
}

char	*get_cmd_path(t_cmd *cmd)
{
	if (cmd->bin)
		return (cmd->bin);
	return (NULL);
}
