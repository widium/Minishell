/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:14 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:40:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_error_parsing(t_env *env)
{
	t_token	*token;

	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			env->error_parsing += check_error_token_cmd(token);
		}
		if (is_token_redirection(token))
		{
			env->error_parsing += check_error_token_redirection(token);
		}
		if (is_token_word(token))
		{
			env->error_parsing += check_error_token_word(token);
		}
		token = token->next;
	}
}

int	check_error_token_word(t_token *token)
{
	int		result;
	t_word	*word;

	word = get_class(token);
	printf("Error : [Unknow token \"%s\"]\n", word->content);
	return (1);
}
