/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:36:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 10:05:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	line_is_finish(char *line, int index)
{
	if (index >= ft_strlen(line) && is_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_not_finish(char *line, int index)
{
	if (index < ft_strlen(line) && is_not_finish(line[index]))
		return (1);
	return (0);
}

int	line_is_empty(char	*line)
{
	if (ft_strlen(line) == 0)
		return (1);
	else
		return (0);
}

int	line_is_not_empty(char	*line)
{
	if (ft_strlen(line) > 0)
		return (1);
	return (0);
}
