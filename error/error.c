/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:35:14 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/12 15:17:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int check_error_parsing(t_env *env)
{
    t_token *token;
    int result;

    token = get_first_token(env);
    while (token)
    {
        if (is_token_cmd(token))
        {
            result = check_error_token_cmd(token);
        }
        if (is_token_redirection(token))
        {
            result = check_error_token_redirection(token);
        }
        if (is_token_word(token))
        {
            result = check_error_token_word(token);
        }
        token = token->next;
    }
    return (result);
}

int check_error_token_word(t_token *token)
{
    int result;
    t_word *word;

    word = get_class(token);
    printf("Error : [Unknow token \"%s\"]\n", word->content);
    return (0);
}


int check_error_token_cmd(t_token *token)
{
    t_cmd *cmd;
    t_cmd *prev_cmd;
    t_cmd *next_cmd;
    int result;

    cmd = get_class(token);    
    if (is_token_cmd(token->next))
    {
        next_cmd = get_class(token->next);
        printf("Error : [Two following cmd \"%s\" && \"%s\"]\n", cmd->content, next_cmd->content);
        return (0);
    }
    else if (is_token_cmd(token->prev))
    {
        prev_cmd = get_class(token->prev);
        printf("Error : [Two following cmd \"%s\" && \"%s\"]\n", prev_cmd->content, cmd->content);
        return (0);
    }
    return (1);
}

int check_error_token_redirection(t_token *token)
{
    t_redirection *redir;
    int result;
    
    redir = get_class(token);
    if (is_token_basic_redirection(token))
    {
        result = check_error_token_basic_redirection(token, redir);
    }
    else if (is_token_heredoc(token))
    {
        result = check_error_token_heredoc(token, redir);
    }
    else if (is_token_pipe(token))
    {
        result = check_error_token_pipe(token, redir);
    }
    return (result);
}

int check_error_token_heredoc(t_token *token, t_redirection *redir)
{
    if (!redir->limiter)
    {
        printf("Error : [limiter after \"%s\" not found]\n", redir->content);
        return (0);
    }
    else if (!(is_token_cmd(token->prev)) || !token->prev)
    {
        printf("Error : [prev_cmd before \"%s\" not found]\n", redir->content);
        return (0);
    }
    return (1);
}

int check_error_token_basic_redirection(t_token *token, t_redirection *redir)
{
    if (!(is_token_file(token->next)) || !token->next)
    {
        printf("Error : [next_file after \"%s\" not found]\n", redir->content);
        return (0);
    }
    else if (!(is_token_cmd(token->prev)) || !token->prev)
    {
        printf("Error : [prev_cmd before \"%s\" not found]\n", redir->content);
        return (0);
    }
    return (1);
}

int check_error_token_pipe(t_token *token, t_redirection *redir)
{
    if (!(is_token_cmd(token->next)) || !token->next)
    {
        printf("Error : [next_cmd after \"%s\" not found]\n", redir->content);
        return (0);
    }
    else if (!(is_token_cmd(token->prev)) || !token->prev)
    {
        printf("Error : [prev_cmd before \"%s\" not found]\n", redir->content);
        return (0);
    }
    return (1);
}