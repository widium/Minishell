/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 17:19:44 by ebennace         ###   ########.fr       */
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
    token->class = NULL;
	token->prev = NULL;
    token->next = NULL;
	return (token);
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


t_cmd   *init_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
        return (NULL);
	cmd->bin = NULL;
	cmd->flags = NULL;
	cmd->complete = NULL;
	cmd->fd_in = -1;
	cmd->fd_out = -1;
	return (cmd);
}

t_file	*init_file(void)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = NULL;
	file->fd = -1;
	return (file);
}

t_single	*init_single(void)
{
	t_single	*single;

	single = (t_single *)malloc(sizeof(t_single));
	if (!single)
		return (NULL);
	single->id = 0;
	single->content = NULL;
	return (single);
}

t_double	*init_double(void)
{
	t_double	*double_q;

	double_q = (t_double *)malloc(sizeof(t_double));
	if (!double_q)
		return (NULL);
	double_q->id = 0;
	double_q->content = NULL;
	return (double_q);
}

t_variable	*init_variable(void)
{
	t_variable	*variable;

	variable = (t_variable *)malloc(sizeof(t_variable));
	if (!variable)
		return (NULL);
	variable->id = 0;
	variable->content = NULL;
	return (variable);
}

t_redirection	*init_redirection(void)
{
	t_redirection	*redir;

	redir = (t_redirection *)malloc(sizeof(t_redirection));
	if (!redir)
		return (NULL);
	redir->id = 0;
	redir->fd_in = 0;
	redir->fd_out = 0;
	return (redir);
}

t_boolean	*init_boolean_operator(void)
{
	t_boolean	*boolean;

	boolean = (t_boolean *)malloc(sizeof(t_boolean));
	if (!boolean)
		return (NULL);
	boolean->id = 0;
	boolean->in = NULL;
	boolean->out = NULL;
	return (boolean);
}

t_wildcard	*init_wildcard(void)
{
	t_wildcard	*wildcard;

	wildcard = (t_wildcard *)malloc(sizeof(t_wildcard));
	if (!wildcard)
		return (NULL);
	wildcard->suffix = NULL;
	wildcard->prefixe = NULL;
	return (wildcard);
}