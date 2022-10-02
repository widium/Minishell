/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_have.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:46:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 14:53:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_have_args(t_cmd *cmd)
{
	if (cmd->first_arg)
		return (1);
	return (0);
}

int	cmd_have_argument(t_cmd *cmd)
{
	if (is_env(cmd) || is_pwd(cmd) || is_cd(cmd)
		|| is_exit(cmd) || is_export(cmd) || is_echo(cmd))
		return (1);
	if ((cmd->args || cmd->arg))
		return (1);
	return (0);
}

int	cmd_have_arg_flags(t_cmd *cmd)
{
	t_arg	*arg;

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

int	cmd_have_flags(t_cmd *cmd)
{
	if (cmd->flags)
		return (1);
	return (0);
}

int	cmd_have_args_array(t_cmd *cmd)
{
	if (cmd->args)
		return (1);
	return (0);
}
