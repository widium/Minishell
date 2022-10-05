/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:53:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 08:43:57 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_dimensions(char **array, char **new_array, int y, int *i)
{
	new_array[y] = malloc_strcpy(array[*i]);
	(*i)++;
}

void	copy_str_in_array(char **new_array, int index, char *str)
{
	new_array[index] = malloc_strcpy(str);
}

char	**ft_arrayjoin_str(char **array, char *str, int pos)
{
	char	**new_array;
	int		size;
	int		i;
	int		y;

	size = len_array(array);
	new_array = malloc(sizeof(char *) * (size + 2));
	i = 0;
	y = 0;
	while (array[i])
	{
		if (y != pos)
			copy_dimensions(array, new_array, y, &i);
		else
			copy_str_in_array(new_array, y, str);
		y++;
	}
	if (y == pos && i >= size)
	{
		copy_str_in_array(new_array, y, str);
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
	size = len_array(array);
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

char	**str_to_array(char *str)
{
	char	**new_args;
	int		i;

	i = 0;
	new_args = malloc(sizeof(char *) * (2));
	copy_str_in_array(new_args, i, str);
	new_args[i + 1] = NULL;
	return (new_args);
}
