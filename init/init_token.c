/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:24:55 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*init_token(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->id = 0;
	token->class = NULL;
	token->prev = NULL;
	token->next = NULL;
	return (token);
}

t_arg	*init_arg(char *content, int id)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->id = id;
	arg->content = content;
	arg->prev = NULL;
	arg->next = NULL;
	return (arg);
}

t_blank	*init_blank(char *content, int id)
{
	t_blank	*blank;

	blank = (t_blank *)malloc(sizeof(t_blank));
	if (!blank)
		return (NULL);
	blank->content = content;
	blank->id = id;
	return (blank);
}

t_word	*init_word(char *content, int id)
{
	t_word	*word;

	word = (t_word *)malloc(sizeof(t_word));
	if (!word)
		return (NULL);
	word->content = content;
	word->id = id;
	return (word);
}

t_cmd	*init_cmd(char *content, int id)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->id = id;
	cmd->content = content;
	cmd->flags = NULL;
	cmd->bin = NULL;
	cmd->arg = NULL;
	cmd->args = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->first_arg = NULL;
	cmd->pid = 0;
	return (cmd);
}
