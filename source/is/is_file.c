/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:50:12 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 15:32:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_file(char *line, int i)
{
	if (!(is_quote(line[i])) && !(is_blank(line[i]))
		&& !(is_separator(line, i)) && is_after_redirect(line, i))
		return (1);
	return (0);
}

int	is_after_redirect(char *line, int index)
{
	index--;
	while (index >= 0)
	{
		if (!(is_blank(line[index])))
		{
			if (is_file_redirection(line, index))
				return (1);
			return (0);
		}
		index--;
	}
	return (0);
}

int	is_after_heredoc(char *line, int index)
{
	index--;
	while (index >= 0)
	{
		if (!(is_blank(line[index])))
		{
			if (is_heredoc(line, index))
				return (1);
			return (0);
		}
		index--;
	}
	return (0);
}

int	is_limiter(char *line, int i)
{
	if (is_after_heredoc(line, i) && !(is_file(line, i)))
		return (1);
	return (0);
}
