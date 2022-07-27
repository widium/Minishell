/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:14:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:19:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all_token(t_env *env)
{
    t_token *token;
    t_token *iter;

    if (!(env->first_token))
        return;
    token = env->first_token;
    while (token)
    {
        iter = token->next;
        disconect_token(token);
        remove_token(token);
        token = iter;
    }
}

void disconect_token(t_token *token)
{
    token->next = NULL;
    token->prev = NULL; 
}

void remove_token(t_token *token)
{
    if (is_token_cmd(token))
    {
        remove_token_cmd(get_class(token));
    }
    else if (is_token_redirection(token))
    {
        remove_token_redir(get_class(token)); 
    }
    else if (is_token_boolean(token))
    {
        remove_token_bool(get_class(token));
    }
    else if (is_token_file(token))
    {
        remove_token_file(get_class(token));
    }
}

void remove_token_cmd(t_cmd *cmd)
{
    free(cmd->bin);
    free_array(cmd->complete);
    free(cmd->flags);
    free(cmd->content);
    remove_all_arg(cmd);
    free(cmd);
    
}

void remove_token_redir(t_redirection *redir)
{
    free(redir->content);
    free(redir->limiter);
    free(redir);
}

void remove_token_bool(t_boolean *boolean)
{
    free(boolean->content);
    free(boolean->first);
    free(boolean->second);
    free(boolean);
}

void remove_token_file(t_file *file)
{
    free(file);
}