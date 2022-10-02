/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:59:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:28:27 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tokenization(t_env *env, char *line)
{
	int	index;

	index = 0;
	while (line_is_not_finish(line, index))
	{
		if (is_word(env, line, index))
		{
			index = word_classification(env, line, index);
		}
		if (is_redirection(line, index))
		{
			index = redirection_classification(env, line, index);
		}
		index++;
	}
}

int	single_tokenization(t_cmd *cmd, char *line, int start, int index)
{
	t_arg	*arg;
	char	*content;

	if (is_finish(line[index]))
	{
		content = get_rest_single_quote(line, start, index, "\'");
	}
	else
	{
		content = malloc_substrcpy(line, start, index);
		index++;
	}
	arg = create_arg(content, TOKEN_SINGLE_QUOTE);
	add_arg_list(cmd, arg);
	return (index);
}

t_token	*cmd_tokenization(char *word, int id)
{
	t_token	*token;

	token = create_token_command(id, word);
	return (token);
}
