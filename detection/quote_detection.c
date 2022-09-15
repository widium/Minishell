/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_detection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:18:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/15 13:10:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


int tokenize_content_single_quote(t_cmd *cmd, char *line, int start, int index)
{
	t_arg *arg;
	char *content;
	int end;

	if (is_finish(line[index]))
	{
	   content = get_rest_of_quote_content(line, start, index, "\'");
	}
	else
	{
		content = malloc_substrcpy(line, start, (index - start) + 1);
		index++;
	}
	arg = create_arg(content, TOKEN_SINGLE_QUOTE);
	add_arg_list(cmd, arg);
	return (index);
}

char *get_content_double_quote(t_cmd *cmd, char *line, int start, int *index)
{
	t_arg *arg;
	char *content;
    
	if (is_finish(line[*index]))
	   content = get_rest_of_quote_content(line, start, *index, "\"");
	else
	{
		content = malloc_substrcpy(line, start, (*index - start) + 1);
		(*index)++;
	}
	return (content);
}

char *get_rest_of_quote_content(char *line, int start, int end, char *quote)
{
	char *content;
	char *heredoc;
	char *dup;

	content = malloc_substrcpy(line, start, (end - start) + 1);
	heredoc = heredoc_not_finish(quote);
	dup = malloc_strcpy(content);
	free(content);
	content = ft_strjoin(dup, heredoc);
	free(dup);
	free(heredoc);
	return (content);
}