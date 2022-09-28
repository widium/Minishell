/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:53:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 17:09:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_dimensions(char **array, char **new_array, int y, int *i)
{
	new_array[y] = malloc_strcpy(array[*i]);
	(*i)++;
}

char	**ft_arrayjoin_str(char **array, char *str, int pos)
{
	char	**new_array;
	int		size;
	int		i;
	int		y;

	size = ft_strlen_array(array);
	new_array = malloc(sizeof(char *) * (size + 2));
	i = 0;
	y = 0;
	while (array[i])
	{
		if (y != pos)
			copy_dimensions(array, new_array, y, &i);
		else
			new_array[y] = malloc_strcpy(str);
		y++;
	}
	if (y == pos && i >= size)
	{
		new_array[y] = malloc_strcpy(str);
		y++;
	}
	new_array[y] = NULL;
	return (new_array);
}

char	**ft_arrayremove_str(char **array, int pos)
{
	char	**new_array;
	int		size;
	int		i;
	int		y;

	if (pos < 0)
		return (array);
	size = ft_strlen_array(array);
	new_array = malloc(sizeof(char *) * size);
	i = 0;
	y = 0;
	while (y < (size - 1))
	{
		if (y != pos)
			new_array[y] = malloc_strcpy(array[i]);
		else
		{	
			i++;
			new_array[y] = malloc_strcpy(array[i]);
		}
		i++;
		y++;
	}
	new_array[y] = NULL;
	return (new_array);
}
