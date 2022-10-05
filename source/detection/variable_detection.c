/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_detection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:49:53 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 14:50:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	variable_detection(char *line, int index)
{
	int		end;

	end = index;
	if (line[index] == '$')
		return (index);
	index++;
	while (line[index])
	{
		if (is_variable_delimiter(line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (is_variable_delimiter(line, index))
		end = index - 1;
	return (end);
}
