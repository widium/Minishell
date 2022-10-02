/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:49:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:25:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	double_quotes_detection(char *line, int index)
{
	int	start;

	start = index;
	index++;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_double_quote(line[index]))
			return (index);
		index++;
	}
	return (start);
}

int	single_quotes_detection(char *line, int index)
{
	int	start;

	start = index;
	index++;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_single_quote(line[index]))
			return (index);
		index++;
	}
	return (start);
}

char	*get_content_double(char *line, int start, int *index)
{
	char	*content;

	if (is_finish(line[*index]))
		content = get_rest_single_quote(line, start, *index, "\"");
	else
	{
		content = malloc_substrcpy(line, start, *index);
		(*index)++;
	}
	return (content);
}

char	*get_rest_single_quote(char *line, int start, int end, char *quote)
{
	char	*content;
	char	*heredoc;
	char	*dup;

	content = malloc_substrcpy(line, start, end);
	heredoc = heredoc_not_finish(quote);
	dup = malloc_strcpy(content);
	free(content);
	content = ft_strjoin(dup, heredoc);
	free(dup);
	free(heredoc);
	return (content);
}
