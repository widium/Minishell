/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:01:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 08:30:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	len_array(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}
