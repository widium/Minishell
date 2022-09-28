/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_class.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:21:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:23:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_cmd(t_cmd *cmd, int index)
{
	printf("[%d][%d] : [%s]\n", index, cmd->id, cmd->content);
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
		printf("   [%d][%d] : [%s]\n", i, iter->id, iter->content);
		i++;
		iter = iter->next;
	}
	printf("\n");
}

void	print_args_array(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	printf("   [ARGS][");
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	printf("]\n");
}

void	print_redirection(t_token *token, t_redir *redir)
{
	printf("[%d][%d] : [%s]\n", token->index, redir->type, redir->content);
	if (redir->type == TOKEN_HERE_DOC)
	{
		printf("    [%s][%s]\n", "TOKEN_LIMITER", redir->limiter);
	}
	else
	{
		printf("   [FD_IN : %d]\n", redir->fd_in);
		printf("   [FD_OUT : %d]\n", redir->fd_out);
	}
	printf("\n");
}
