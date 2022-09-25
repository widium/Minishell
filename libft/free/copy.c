/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:47:05 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 12:41:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*malloc_strcpy(char *origin)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(origin) + 1));
	i = 0;
	while (origin[i])
	{
		str[i] = origin[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*malloc_strcpy_index(char *origin, int len)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * len + 1);
	i = 0;
	while (origin[i] && i < len)
	{
		str[i] = origin[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*malloc_strcpy_after_index(char *origin, int index)
{
	int		len;
	int		range;
	char	*new;
	int		i;
	
	len = ft_strlen(origin);
	range = len - index;
	i = 0;
	new = malloc(sizeof(char) * range + 1);
	while (i < range)
	{
		new[i] = origin[index + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*malloc_substrcpy(char *origin, int index, int len)
{
	char	*new;
	int		i;
	
	i = 0;
	new = malloc(sizeof(char) * len + 1);
	while (i < len)
	{
		new[i] = origin[index + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**malloc_strcpy_array(char **origin)
{
	size_t	i;
	size_t	len;
	char	**array;

	len = col_count(origin);
	array = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (origin[i])
	{
		array[i] = malloc_strcpy(origin[i]);
		i++;
	}
	array[i] = 0;
	return (array);
}

size_t	col_count(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
