/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:53:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:26:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	word_detection(t_env *env, char *line, int index)
{
	while (line[index])
	{
		if (is_delimiter(env, line, index))
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

int	file_detection(char *line, int index)
{
	while (line[index])
	{
		if (is_separator(line, index))
		{
			--index;
			if (is_blank(line[index]))
				--index;
			return (index);
		}
		index++;
	}
	return (index);
}

int	blank_detection(char *line, int index)
{
	while (line[index] && is_blank(line[index]))
	{
		index++;
	}
	return (index);
}

int	blank_escape(char *line, int index)
{
	while (line[index])
	{
		if (!(is_blank(line[index])))
			return (index);
		index++;
	}
	return (index);
}
