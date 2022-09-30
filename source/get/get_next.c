/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:02:21 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 14:03:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

t_token	*get_next_token_bin(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_bin(token))
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
