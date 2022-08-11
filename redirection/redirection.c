/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:17:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/11 17:28:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void processing_redirection(t_env *env)
{
    t_token *token;

    // printf("------Processing Redirection ------\n");
    if (have_token_redirection(env))
    {
        token = get_first_token_redirection(env);
        while (token)
        {
            manage_fd_for_redirection(token);
            token = get_next_token_redirection(env, token);
        }
    }
    else
        return ;   
}

int have_token_redirection(t_env *env)
{
    t_token *token;

    if (!(have_token(env)))
        return (0);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (1);
        token = token->next;
    }
    return (0); 
}

void change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out)
{
    cmd->fd_in = fd_in;
    cmd->fd_out = fd_out;
}