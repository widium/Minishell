/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:58:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 17:23:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_token *create_token(char *content, int id)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = choose_class(content, id);
	
	return (token);
}

void *choose_class(char *content, int id)
{
    if (id == TOKEN_BLANK)
		return (init_blank(content, id));
    else if (id == TOKEN_WORD)
        return (init_word(content, id));
	return (NULL);
}

void connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}