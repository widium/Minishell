/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:52:44 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/12 15:02:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_token_redirection(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_INPUT_CHEVRON || token->id == TOKEN_OUTPUT_CHEVRON || token->id == TOKEN_REDIRECTION ||
     token->id == TOKEN_APPEND_CHEVRON || token->id == TOKEN_HERE_DOC || token->id == TOKEN_PIPE)
        return (1);
    return (0);
}

int is_token_pipe(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_PIPE)
        return (1);
    return (0);
}

int is_token_heredoc(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_HERE_DOC)
        return (1);
    return (0);
}

int is_token_input_chevron(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_INPUT_CHEVRON)
        return (1);
    return (0);
}

int is_token_append_chevron(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_APPEND_CHEVRON)
        return (1);
    return (0);
}

int is_token_output_chevron(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_OUTPUT_CHEVRON)
        return (1);
    return (0);
}

int is_token_basic_redirection(t_token *token)
{
    if (!token)
        return (0);
    if (is_token_output_chevron(token) || is_token_input_chevron(token) ||
     is_token_append_chevron(token))
        return (1);
    return (0);
}


int is_redir_heredoc(t_redirection *redir)
{
    if (!redir)
        return (0);
    if (redir->type == TOKEN_HERE_DOC)
        return (1);
    return (0);
}

int is_token_boolean(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_AND || token->id == TOKEN_OR || token->id == TOKEN_BOOLEAN)
        return (1);
    return (0);
}

int is_token_word(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_WORD)
        return (1);
    return (0);
}

int is_token_cmd(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_BUILT_IN || token->id == TOKEN_BINARY || token->id == TOKEN_COMMAND)
        return (1);
    return (0);
}

int is_cmd_bin(t_cmd *cmd)
{
    if (!cmd)
        return (0);
    if (cmd->id == TOKEN_BINARY || cmd->id == TOKEN_COMMAND)
        return (1);
    return (0);
}

int is_cmd_built_in(t_cmd *cmd)
{
    if (!cmd)
        return (0);
  if (cmd->id == TOKEN_BUILT_IN || cmd->id == TOKEN_COMMAND)
        return (1);
    return (0);  
}

int is_token_file(t_token *token)
{
    if (!token)
        return (0);
    if (token->id == TOKEN_FILE)
        return (1);
    return (0);
}