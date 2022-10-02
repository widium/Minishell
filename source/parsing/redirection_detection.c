/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_detection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:26:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redirection_detection(char *line, int index)
{
	int	start;

	start = index;
	while (line_is_not_finish(line, index))
	{
		if (!(is_redirection(line, index)))
		{
			return (index - 1);
		}
		index++;
	}
	if (index == ft_strlen(line) && is_redirection(line, index -1))
	{
		return (index - 1);
	}
	return (start);
}

int	limiter_detection(char *line, int index)
{
	while (line[index])
	{
		if (is_blank(line[index]) || is_separator(line, index))
		{
			return (index - 1);
		}
		if (is_double_quote(line[index]))
		{
			index = double_quotes_detection(line, index);
		}
		if (is_single_quote(line[index]))
		{
			index = single_quotes_detection(line, index);
		}
		index++;
	}
	return (index);
}
