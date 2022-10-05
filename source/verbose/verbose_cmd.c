/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:03:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmd_info(t_cmd *cmd)
{
	ft_printf(" ---[%s]---\n", cmd->content);
	ft_printf(" | type : [%d]\n", cmd->id);
	if (is_cmd_bin(cmd))
	{
		ft_printf(" | path : [%s]\n", cmd->bin);
		ft_printf(" | args : [");
		print_array(cmd->args);
		ft_printf("]\n");
	}
	else if (is_cmd_built_in(cmd))
	{
		ft_printf(" | arg : [%s]\n", cmd->arg);
		ft_printf(" | flags : [%s]\n", cmd->flags);
	}
	ft_printf(" | fd_in : [%d]\n", cmd->fd_in);
	ft_printf(" | fd_out : [%d]\n", cmd->fd_out);
	if (cmd_have_args(cmd))
		print_args(cmd);
	ft_printf(" ----------------\n");
}

void	print_all_cmd_info(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;

	token = get_first_token_cmd(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			cmd = get_class(token);
			print_cmd_info(cmd);
		}
		token = get_next_token_cmd(token);
	}
}
