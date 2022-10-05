/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:56:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 09:17:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	compare_line(char *line, char *limiter, int fd_tmp)
{
	if (same_str(limiter, line, (ft_strlen(limiter))))
	{
		free(line);
		return (1);
	}
	else
	{
		ft_putstr_fd(line, fd_tmp);
		free(line);
		return (0);
	}
}

char	*heredoc_prompt(char *limiter)
{
	int		fd_tmp;
	char	*line;
	char	*tmp_file_name;

	tmp_file_name = "tmp.txt";
	fd_tmp = open(tmp_file_name, O_CREAT | O_WRONLY, 0777);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = mini_get_next_line(STDIN_FILENO);
		if (line)
		{
			if (compare_line(line, limiter, fd_tmp))
				break ;
		}
	}
	close(fd_tmp);
	unlink("tmp.txt");
	return (tmp_file_name);
}

char	*heredoc_not_finish(char *limiter)
{
	int		fd_tmp;
	char	*line;
	char	*content;

	fd_tmp = open("tmp.txt", O_CREAT | O_WRONLY, 0777);
	while (1)
	{
		ft_putstr_fd("finish_quote> ", 1);
		line = mini_get_next_line(STDIN_FILENO);
		if (line)
		{
			if (compare_line(line, limiter, fd_tmp))
				break ;
		}
	}
	close(fd_tmp);
	content = read_and_extract_content_file("tmp.txt");
	unlink("tmp.txt");
	return (content);
}

char	*read_and_extract_content_file(char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = ft_calloc(BUFF_SIZE, sizeof(char));
	if (read(fd, buf, BUFF_SIZE) != -1)
		return (buf);
	else
		free(buf);
	return (NULL);
}
