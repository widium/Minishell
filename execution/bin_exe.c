/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 12:50:18 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	bin_execution(t_env *env, t_cmd *cmd, char **variables)
{
	int		pid;
	char	*path;
	char	**args;

	path = get_cmd_path(cmd);
	args = get_cmd_args(cmd);
	pid = fork();
	if (pid == 0)
	{
		if (cmd_have_standart_fd(cmd))
		{
			execve(path, args, variables);
			perror("Command failure : ");
		}
		else
		{
			redirect_cmd(cmd);
			close_all_fd(env);
			execve(path, args, variables);
			perror("Command failure : ");
		}
	}
	else
		cmd->pid = pid;
}
