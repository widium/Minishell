/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/11 18:05:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"
# include "../token.h"

t_token *init_token(void)
{
    t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->id = 0;
    token->content = NULL;
	token->prev = NULL;
    token->next = NULL;
	return (token);
}

t_token *create_token(char *content, int id)
{
	t_token *token;

	token = init_token();
	token->content = content;
	token->id = id;
	return (token);
}

void connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}