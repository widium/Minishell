/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:22:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 15:24:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_chained_list(t_env *env)
{
	t_token	*iter;

	iter = env->first_token;
	printf("==== Parsing ====\n");
	while (iter)
	{
		print_token(iter);
		iter = iter->next;
	}
	printf("=========\n");
}

void	print_token(t_token *token)
{
	if (is_token_redirection(token))
	{
		print_redirection(token, get_class(token));
	}
	else if (is_token_cmd(token))
	{
		print_cmd(get_class(token), token->index);
	}
	else if (is_token_file(token))
	{
		printf("[%d][%d] : [%s]\n", token->index,
			token->id, ((t_file *)token->class)->name);
		printf("   [FD : %d]\n\n", ((t_file *)token->class)->fd);
	}
	else
		printf("[%d][%d] : [%s]\n\n", token->index,
			token->id, ((t_word *)token->class)->content);
}
