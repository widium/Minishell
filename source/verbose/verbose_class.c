/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_class.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:21:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmd(t_cmd *cmd, int index)
{
	ft_printf("[%d][%d] : [%s]\n", index, cmd->id, cmd->content);
	if (cmd_have_args(cmd))
		print_args(cmd);
	else if (cmd_have_args_array(cmd))
		print_args_array(cmd->args);
}

void	print_args(t_cmd *cmd)
{
	t_arg	*iter;
	int		i;

	i = 1;
	iter = cmd->first_arg;
	if (!iter)
		return ;
	while (iter)
	{
		ft_printf("   [%d][%d] : [%s]\n", i, iter->id, iter->content);
		i++;
		iter = iter->next;
	}
	ft_printf("\n");
}

void	print_args_array(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	ft_printf("   [ARGS][");
	while (args[i])
	{
		ft_printf("%s", args[i]);
		i++;
	}
	ft_printf("]\n");
}

void	print_redirection(t_token *token, t_redir *redir)
{
	ft_printf("[%d][%d] : [%s]\n", token->index, redir->type, redir->content);
	if (redir->type == TOKEN_HERE_DOC)
	{
		ft_printf("    [%s][%s]\n", "TOKEN_LIMITER", redir->limiter);
	}
	else
	{
		ft_printf("   [FD_IN : %d]\n", redir->fd_in);
		ft_printf("   [FD_OUT : %d]\n", redir->fd_out);
	}
	ft_printf("\n");
}
