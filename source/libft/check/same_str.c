/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:31:54 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:51:27 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	same_str(char *first, char *second, int size)
{
	int	i;

	if (size < 0)
		size = ft_strlen(first);
	i = 0;
	while (first[i] && second[i] && i < size)
	{
		if (first[i] != second[i])
			return (0);
		++i;
	}
	if (i == size)
		return (1);
	return (0);
}

int	same_str_index(char *first, char *second, int size, int index)
{
	int	i;

	i = 0;
	if (size < 0)
		size = ft_strlen(first);
	while (first[index] && second[i] && i < size)
	{
		if (first[index] != second[i])
			return (0);
		++index;
		++i;
	}
	if (i == size)
		return (1);
	return (0);
}

int	index_diff(char *first, char *second, int size)
{
	int	i;

	if (size < 0)
		size = ft_strlen(first);
	i = 0;
	while (first[i] && second[i] && i < size)
	{
		if (first[i] != second[i])
			return (i);
		++i;
	}
	return (i);
}
