/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:01:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/11 16:00:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int single_quotes_extraction(t_cmd *cmd, char *line, int index)
{
	t_arg *arg;
	char *content;
	int start;
	int end;

	index++;
	start = index;
	end = index;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_single_quote(line[index]))
		{
		   end = index - 1;
		   break; 
		} 
		index++;
	}
	end = tokenize_content_single_quote(cmd, line, start, index);
	return (end);
}

int double_quotes_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	int start;
	char *content;

	index++;
	start = index;
	while (line[index])
	{
		while (line[index] && is_back_slash(line[index]))
			index++;
		if (is_double_quote(line[index]))
		{
			index--;
			break;
		}
		index++;
	}
	content = get_content_double_quote(cmd, line, start, &index);
	parse_and_tokenize_double_quote(env, cmd, content);
	free(content);
	return (index);
}

void parse_and_tokenize_double_quote(t_env *env, t_cmd *cmd, char *content)
{
	t_arg *arg;
	int index;
	int new_index;

	new_index = 0;
	index = 0;
	while (content[index])
	{
		if (is_variable(env, content, index))
		{
			new_index = variables_extraction(env, cmd, content, index);
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