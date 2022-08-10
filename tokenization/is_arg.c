/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:58:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/10 09:09:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


int is_arg_variable(t_arg *arg)
{
    if (arg->id == TOKEN_VARIABLE)
        return (1);
    return (0);
}

int cmd_have_args(t_cmd *cmd)
{
    if (cmd->first_arg)
        return (1);
    return (0);
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