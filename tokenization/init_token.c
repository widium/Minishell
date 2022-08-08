/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 10:48:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


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

t_arg *init_arg(char *content, int id)
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


t_cmd   *init_cmd(char *content, int id)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
        return (NULL);
	cmd->id = id;
	cmd->content = content;
	cmd->bin = NULL;
	cmd->args = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->first_arg = NULL;
	return (cmd);
}

t_file	*init_file(char *name, int fd)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = name;
	file->fd = fd;
	return (file);
}

t_single	*init_single(char *content, int id)
{
	t_single	*single;

	single = (t_single *)malloc(sizeof(t_single));
	if (!single)
		return (NULL);
	single->id = id;
	single->content = content;
	return (single);
}

t_double	*init_double(char *content, int id)
{
	t_double	*double_q;

	double_q = (t_double *)malloc(sizeof(t_double));
	if (!double_q)
		return (NULL);
	double_q->id = id;
	double_q->content = content;
	return (double_q);
}

t_redirection	*init_redirection(int type, char *content)
{
	t_redirection	*redir;

	redir = (t_redirection *)malloc(sizeof(t_redirection));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = NULL;
	redir->content = content;
	return (redir);
}

t_redirection	*init_heredoc(int type, char *content, char *limiter)
{
	t_redirection	*redir;

	redir = (t_redirection *)malloc(sizeof(t_redirection));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = limiter;
	redir->content = content;
	return (redir);
}

t_boolean	*init_boolean_operator(char * content, char *first, char *second, int id)
{
	t_boolean	*boolean;

	boolean = (t_boolean *)malloc(sizeof(t_boolean));
	if (!boolean)
		return (NULL);
	boolean->id = id;
	boolean->first = first;
	boolean->second = second;
	boolean->content = content;
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