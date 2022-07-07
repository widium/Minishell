/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:47:54 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 14:49:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int search_string(char *str1, char *str2)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (str1[i])
	{
		if (is_in_str(str1, i, str2))
			count++;
		i++;
	}
	return (count);
}

int	is_in_str(char *first, int i, char *second)
{
	int second_i;
	int second_size;

	second_size = ft_strlen(second);
	second_i = 0;
	while (is_not_NULL(first[i], second[second_i]) && second_i < second_size)
	{
		if (first[i] != second[second_i])
			return (0);
		// printf("%c %c\n", first[i], second[i]);
		++i;
		++second_i;
	}
	if (second_i == second_size && second[second_i] == '\0')
		return (1);
	return (0);
}