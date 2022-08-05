/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:17:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/05 16:45:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void redirection(t_env *env)
{
    t_token *token;
    t_cmd *prev_cmd;
    t_cmd *next_cmd;
    t_file *next_file;
    int pipes;

    
    if (have_token_redirection(env))
    {
        token = get_first_token_redirection(env);
        // pipes = get_nbr_pipes(env);
        prev_cmd = get_prev_cmd(token);
        next_cmd = get_next_cmd(token);
        next_file = get_next_file(token);
        print_redirect_info(token, prev_cmd, next_cmd, next_file);
    }
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