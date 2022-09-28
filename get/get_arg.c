/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:39:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 15:51:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_arg	*get_first_arg(t_cmd *cmd)
{
	if (cmd->first_arg)
		return (cmd->first_arg);
	return (0);
}

char	**get_cmd_args(t_cmd *cmd)
{
	if (cmd->args)
		return (cmd->args);
	return (NULL);
}

int	get_number_args(t_cmd *cmd)
{
	int		nb;
	t_arg	*arg;

	if (!(cmd_have_args(cmd)))
		return (0);
	arg = get_first_arg(cmd);
	nb = 0;
	while (arg)
	{
		nb++;
		arg = arg->next;
	}
	return (nb);
}

t_arg	*get_cmd_flags(t_cmd *cmd)
{
	t_arg	*arg;

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
