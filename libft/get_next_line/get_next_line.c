/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:02:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 08:17:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

#include "../libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	index_newline(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (-1);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_append(char **statik, char *buf, int retour)
{
	char	*temp;

	if (!buf)
		return ;
	buf[retour] = '\0';
	temp = ft_strjoin(*statik, buf);
	free(*statik);
	*statik = temp;
}

char	*ft_separation(char **statik, int retour)
{
	char		*ret;
	char		*rest;
	int			size;

	if (!**statik)
		free(*statik);
	if (!**statik)
		return (NULL);
	size = index_newline(*statik) + 1;
	if (size == 0)
		size = ft_strlen(*statik);
	ret = ft_substr(*statik, 0, size);
	rest = ft_substr(*statik, size, ft_strlen(*statik) - size);
	free(*statik);
	if (retour == 0)
	{
		free(rest);
		*statik = NULL;
		return (ret);
	}
	*statik = rest;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*statik;
	int			index;
	int			retour;
	char		buf[BUFFER_SIZE + 1];

	index = -1;
	if (read(fd, 0, 0))
		return (NULL);
	while (1)
	{
		index = index_newline(statik);
		if (index > -1)
			break ;
		retour = read(fd, buf, BUFFER_SIZE);
		if (retour == 0)
			break ;
		if (!statik)
			statik = ft_substr(buf, 0, retour);
		else
			ft_append(&statik, buf, retour);
	}
	if (!statik)
		return (NULL);
	return (ft_separation(&statik, retour));
}

char	*mini_get_next_line(int fd)
{
	char	*start;
	char	*cursor;

	start = malloc(10000);
	cursor = start;
	while (read(fd, cursor, 1) > 0)
	{
		if (*cursor == '\n')
			break ;
		cursor++;
	}
	if (cursor > start)
	{
		*cursor = 0;
		return (start);
	}
	free(start);
	return (NULL);
}
