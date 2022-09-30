/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:05:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:28:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	concatenate_cmd_args(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;

	token = env->first_token;
	while (token)
	{
		if (is_token_cmd(token))
		{
			cmd = get_class(token);
			if (cmd_have_args(cmd))
			{
				if (is_cmd_bin(cmd))
				{
					remove_blank_arg(cmd);
					cmd->args = cmd_list_to_array(cmd);
				}
				else if (is_cmd_built_in(cmd))
					cmd->arg = cmd_list_to_string(cmd);
			}
		}
		token = token->next;
	}
}

void	remove_blank_arg(t_cmd *cmd)
{
	t_arg	*arg;
	t_arg	*iter;

	iter = get_first_arg(cmd);
	arg = iter;
	while (iter)
	{
		iter = arg->next;
		if (is_arg_blank(arg))
		{
			if (arg->index == 1)
				cmd->first_arg = NULL;
			remove_arg(arg);
		}
		arg = iter;
	}
}
