/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:13:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 15:23:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	is_blank_argument(t_env *env, char *line, int index)
{
	if (is_blank(line[index]) && !(is_blank(line[index + 1]))
		&& !(is_separator(line, index + 1)) && !(is_variable(env, line, index))
		&& line[index] != '$' && !((is_finish(line[index + 1]))))
		return (1);
	return (0);
}

int	is_blank_before_redirection(char *line, int index)
{
	if (is_blank(line[index]) && is_separator(line, index + 1))
	{
		while (line[index] && is_blank(line[index]))
		{
			if (is_redirection(line, index + 1))
			{
				return (1);
			}
			index++;
		}
	}
	return (0);
}

int	is_blank_before_finish(char *line, int index)
{
	if (is_blank(line[index]))
	{
		while (line[index] && is_blank(line[index]))
		{
			if (is_finish(line[index + 1]))
			{
				return (1);
			}
			index++;
		}
	}
	return (0);
}
