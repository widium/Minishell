/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:52:44 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 20:48:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_token_redirection(t_token *token)
{
    if (token->id == TOKEN_INPUT_CHEVRON || token->id == TOKEN_OUTPUT_CHEVRON || token->id == TOKEN_REDIRECTION ||
     token->id == TOKEN_APPEND_CHEVRON || token->id == TOKEN_HERE_DOC || token->id == TOKEN_PIPE)
        return (1);
    return (0);
}

int is_token_boolean(t_token *token)
{
    if (token->id == TOKEN_AND || token->id == TOKEN_OR || token->id == TOKEN_BOOLEAN)
        return (1);
    return (0);
}

int is_token_cmd(t_token *token)
{
    if (token->id == TOKEN_BUILT_IN || token->id == TOKEN_BINARY || token->id == TOKEN_COMMAND)
        return (1);
    return (0);
}

int is_token_file(t_token *token)
{
    if (token->id == TOKEN_FILE)
        return (1);
    return (0);
}