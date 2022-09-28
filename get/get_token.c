/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:40:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 11:54:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*get_first_token(t_env *env)
{
	if (env->first_token)
		return (env->first_token);
	return (0);
}

t_cmd	*get_first_cmd(t_env *env)
{
	t_token	*token;

	if (!(get_first_token(env)))
		return (NULL);
	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
			return (get_class(token));
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_cmd(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*get_next_token_built_in(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_built_in(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_file	*get_next_token_file(t_token *token)
{
	while (token)
	{
		if (is_token_file(token))
			return (get_class(token));
		token = token->next;
	}
	return (NULL);
}
