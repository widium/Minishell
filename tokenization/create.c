/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:58:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/23 15:00:44 by ebennace         ###   ########.fr       */
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

t_arg *create_arg(char *content, int id)
{
	t_arg *arg;

	arg = init_arg(content, id);
	return (arg);
}

void *choose_class(char *content, int id)
{
    if (id == TOKEN_BLANK)
		return (init_blank(content, id));
    else if (id == TOKEN_WORD)
        return (init_word(content, id));
	else if (id == TOKEN_DOUBLE_QUOTE)
		return (init_double(content, id));
	else if (id == TOKEN_SINGLE_QUOTE)
		return (init_single(content, id));
	return (NULL);
}

char *get_content(t_token *token)
{
    if (token->id == TOKEN_BLANK)
		return (((t_blank *)token->class)->content);
    else if (token->id == TOKEN_WORD)
        return (((t_word *)token->class)->content);
    else if (token->id == TOKEN_DOUBLE_QUOTE)
        return (((t_double *)token->class)->content);
	else if (token->id == TOKEN_SINGLE_QUOTE)
        return (((t_single *)token->class)->content);
	return (NULL);
}

char *get_file_name(t_token *token)
{
    return (((t_file *)token->class)->name);
}

int get_file_fd(t_token *token)
{
    return (((t_file *)token->class)->fd);
}


void connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token->next = next_token;
	next_token->prev = curr_token;
}

void connect_arg(t_arg *curr_arg, t_arg *next_arg)
{
	curr_arg->next = next_arg;
	next_arg->prev = curr_arg;
}

t_token *create_token_bool(char *content, char *first, char *second, int id)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = init_boolean_operator(content, first, second, id);
	
	return (token);
}

t_token *create_token_redir(int type, char *content)
{
	t_token *token;

	token = init_token();
	token->id = type;
	token->class = init_redirection(type, content);
	
	return (token);
}

t_token *create_token_heredoc(int type, char *content, char *limiter)
{
	t_token *token;

	token = init_token();
	token->id = type;
	token->class = init_heredoc(type, content, limiter);
	
	return (token);
}

t_token *create_token_variable(int id, char *content)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = init_variable(content);
	
	return (token);
}

t_token *create_token_command(int id, char *content)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = init_cmd(content, id);
	
	return (token);
}

t_token *create_token_file(char *name, int fd, int id)
{
	t_token *token;

	token = init_token();
	token->id = id;
	token->class = init_file(name, fd);
	return (token);
}