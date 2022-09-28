/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 17:50:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt(t_env	*env)
{
	char	*read_line;

	while (1)
	{
		use_signal();
		read_line = get_line(env);
		if (!read_line)
		{
			printf("exit\n");
			break ;
		}
		execute_line(env, read_line);
	}
}

void	create_history(t_env *env, char *line)
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
