/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:14:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:59:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_all_token(t_env *env)
{
	t_token	*token;
	t_token	*iter;

	if (!(env->first_token))
		return ;
	token = get_first_token(env);
	while (token)
	{
		iter = token->next;
		disconect_token(token);
		remove_token(token);
		token = iter;
	}
	env->first_token = NULL;
}

void	remove_token(t_token *token)
{
	if (is_token_cmd(token))
	{
		remove_token_cmd(get_class(token));
	}
	else if (is_token_redirection(token))
	{
		remove_token_redir(get_class(token));
	}
	else if (is_token_file(token))
	{
		remove_token_file(get_class(token));
	}
	else if (is_token_word(token))
	{
		remove_token_word(get_class(token));
	}
	free(token);
}
