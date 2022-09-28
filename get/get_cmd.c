/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:41:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 15:51:21 by ebennace         ###   ########.fr       */
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

t_cmd	*get_next_cmd(t_token *token)
{
	while (token)
	{
		if (is_token_cmd(token))
			return (get_class(token));
		token = token->next;
	}
	return (NULL);
}

char	*get_cmd_path(t_cmd *cmd)
{
	if (cmd->bin)
		return (cmd->bin);
	return (NULL);
}
