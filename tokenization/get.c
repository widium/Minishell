/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:11:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 16:03:48 by ebennace         ###   ########.fr       */
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