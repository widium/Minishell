/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:34:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:35:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_finish(char c)
{
	if (c == '\0')
		return (1);
	return (0);
}

int	is_not_finish(char c)
{
	if (c != '\0')
		return (1);
	return (0);
}

int	index_not_over_flow(char *line, int index)
{
	if (index < ft_strlen(line))
		return (1);
	return (0);
}

int	index_is_over_flow(char *line, int index)
{
	if (index >= ft_strlen(line))
		return (1);
	return (0);
}
