/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:40:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 14:02:49 by ebennace         ###   ########.fr       */
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
