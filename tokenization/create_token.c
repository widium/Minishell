/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:58:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:48:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*create_token_word(char *content, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_word(content, id);
	return (token);
}

t_arg	*create_arg(char *content, int id)
{
	t_arg	*arg;

	arg = init_arg(content, id);
	return (arg);
}

t_token	*create_token_redir(char *line, int index, int new_index)
{
	char	*content;
	int		type;
	t_token	*token;

	content = malloc_substrcpy(line, index, new_index);
	type = type_of_redirect(content);
	token = init_token();
	token->id = type;
	token->class = init_redirection(type, content);
	return (token);
}

t_token	*create_token_command(int id, char *content)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_cmd(content, id);
	return (token);
}

t_token	*create_token_file(char *name, int fd, int id)
{
	t_token	*token;

	token = init_token();
	token->id = id;
	token->class = init_file(name, fd);
	return (token);
}
