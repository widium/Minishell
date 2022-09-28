/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:28:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 15:29:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_standard_fd(int fd)
{
	if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
		return (1);
	return (0);
}

int	is_not_standard_fd(int fd)
{
	if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
		return (1);
	return (0);
}

int	cmd_have_standart_fd(t_cmd *cmd)
{
	if (is_standard_fd(cmd->fd_in) && is_standard_fd(cmd->fd_out))
		return (1);
	return (0);
}
