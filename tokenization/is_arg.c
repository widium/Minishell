/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:58:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/09 12:43:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int is_arg_variable(t_arg *arg)
{
    if (!arg)
        return (0);
    if (arg->id == TOKEN_VARIABLE)
        return (1);
    return (0);
}

int is_arg_flags(t_arg *arg)
{
    if (!arg)
        return (0);
    if (arg->id == TOKEN_FLAGS)
        return (1);
    return (0);
}

int cmd_have_args(t_cmd *cmd)
{
    if (cmd->first_arg)
        return (1);
    return (0);
}

int cmd_have_argument(t_cmd *cmd)
{
    if (is_env(cmd))
        return (1);
    if ((cmd->args || cmd->arg))
        return (1);
    return (0);
}

int cmd_have_arg_flags(t_cmd *cmd)
{
    t_arg *arg;

    if (!(cmd_have_args(cmd)))
        return (0);
    arg = get_first_arg(cmd);
    while (arg)
    {
        if (is_arg_flags(arg))
            return (1);
        arg = arg->next;
    }
    return (0);
}

int cmd_have_flags(t_cmd *cmd)
{
    if (cmd->flags)
        return (1);
    return (0);
}


t_arg *get_cmd_flags(t_cmd *cmd)
{
    t_arg *arg;

    if (!(cmd_have_args(cmd)))
        return (0);
    arg = get_first_arg(cmd);
    while (arg)
    {
        if (is_arg_flags(arg))
            return (arg);
        arg = arg->next;
    }
    return (NULL);
}

int cmd_have_args_array(t_cmd *cmd)
{
    if (cmd->args)
        return (1);
    return (0);
}

int have_token(t_env *env)
{
    if (env->first_token)
        return (1);
    return (0);
}

int token_have_args(t_token *token)
{
    if (((t_cmd *)token->class)->first_arg)
        return (1);
    return (0);
}