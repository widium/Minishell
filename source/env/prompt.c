/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(t_env	*env)
{
	char	*read_line;

	while (1)
	{
		use_signal();
		read_line = get_line();
		if (!read_line)
		{
			ft_printf("exit\n");
			break ;
		}
		if (line_is_not_empty(read_line))
			execute_line(env, read_line);
		free(read_line);
	}
}

void	create_history(char *line)
{
	int	fd;

	add_history(line);
	fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
	write_line(line, fd);
}

void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}
