/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 16:11:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cmd_tokenizer(t_env *env, char *line, char *content, int index)
{
	t_token	*token;

	token = cmd_classification(env, content);
	if (index_not_over_flow(line, index) && !(is_separator(line, index)))
	{
		index = blank_detection(line, index);
		index = argument_extraction(env, get_class(token), line, index);
	}
	add_token_list(env, token);
	return (index);
}

t_arg	*arg_tokenizer(char *line, int start, int end, int id)
{
	t_arg	*arg;
	char	*content;

	if (line == NULL)
		content = NULL;
	else
		content = malloc_substrcpy(line, start, end);
	arg = create_arg(content, id);
	return (arg);
}

int	flags_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	t_arg	*arg;
	int		start;
	int		end;

	end = index;
	start = index;
	while (line[index])
	{
		if (is_delimiter(env, line, index))
		{
			end = index -1;
			break ;
		}
		index++;
	}
	if (!(is_delimiter(env, line, index - 1)))
		end = index - 1;
	arg = arg_tokenizer(line, start, end, TOKEN_FLAGS);
	add_arg_list(cmd, arg);
	return (end + 1);
}

int	variable_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_index;

	if (is_variable(env, line, index))
	{
		new_index = variables_tokenization(env, cmd, line, index);
	}
	else
	{
		new_index = word_arg_detection(env, line, index);
	}
	return (new_index);
}

int	variables_tokenization(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_index;
	char	*name;
	t_arg	*arg;

	new_index = variable_detection(line, ++index);
	name = malloc_substrcpy(line, index, new_index);
	if (variable_exist(env, name))
	{
		arg = create_arg(name, TOKEN_VARIABLE);
		add_arg_list(cmd, arg);
	}
	else
		free(name);
	return (new_index);
}
