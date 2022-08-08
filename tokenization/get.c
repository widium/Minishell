/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:11:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 17:33:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_arg *get_first_arg(t_cmd *cmd)
{
    if (cmd->first_arg)
        return (cmd->first_arg);
    return (0);
}

t_token *get_first_token(t_env *env)
{   
    if (env->first_token)
        return (env->first_token);
    return (0);
}

t_cmd *get_first_cmd(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_redirection *get_first_redirection(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_token *get_first_token_redirection(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_token *get_next_token_redirection(t_env *env, t_token *token)
{
    while (token)
    {
        if (is_token_redirection(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

int get_nbr_pipes(t_env *env)
{
    t_token *token;
    int count;

    if (!(get_first_token(env)))
        return (0);
    count = 0;
    token = get_first_token(env);
    while (token)
    {
        if (is_token_pipe(token))
            count++;
        token = token->next;
    }
    return (count);
}

t_cmd *get_prev_cmd(t_token *token)
{ 
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->prev;
    }
    return (NULL);
}

t_cmd *get_next_cmd(t_token *token)
{   
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_file *get_next_file(t_token *token)
{   
    while (token)
    {
        if (is_token_file(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

char *get_cmd_path(t_cmd *cmd)
{
    if (cmd->bin)
        return (cmd->bin);
    return (NULL);
}

char **get_cmd_args(t_cmd *cmd)
{
    if (cmd->args)
        return (cmd->args);
    return (NULL);
}

char **get_env_variables(t_env *env)
{
    if (env->variable->variables)
        return (env->variable->variables);
    return (NULL);
}