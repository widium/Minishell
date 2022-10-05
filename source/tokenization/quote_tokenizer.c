/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tokenizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:01:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 17:40:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	single_tokenizer(t_cmd *cmd, char *line, int index)
{
	int		start;
	int		end;

	index++;
	start = index;
	end = index;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_single_quote(line[index]))
		{
			index--;
			break ;
		}
		index++;
	}
	end = single_tokenization(cmd, line, start, index);
	return (end);
}

int	double_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		start;
	char	*content;

	index++;
	start = index;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_double_quote(line[index]))
		{
			index--;
			break ;
		}
		index++;
	}
	content = get_content_double(line, start, &index);
	double_tokenization(env, cmd, content);
	free(content);
	return (index);
}

void	double_tokenization(t_env *env, t_cmd *cmd, char *content)
{
	int		index;
	int		new_index;

	new_index = 0;
	index = 0;
	while (content[index])
	{
		if (is_variable_word(content, index))
		{
			new_index = variables_tokenization(env, cmd, content, index);
			index = new_index;
		}
		else
		{
			new_index = string_extraction(env, cmd, content, index);
			index = new_index;
		}
		index++;
	}
}
