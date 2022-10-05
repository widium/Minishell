/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*word_tokenizer(char *content, int id)
{
	t_token	*token;

	token = create_token_word(content, id);
	return (token);
}

void	word_arg_tokenizer(t_env *env, t_cmd *cmd, char *content)
{
	t_arg	*arg;

	if (is_valide_variable(env, content))
	{
		arg = create_arg(content, TOKEN_WORD);
		add_arg_list(cmd, arg);
	}
	else
		free(content);
}

t_token	*file_tokenizer(char *name, int id)
{
	t_token	*token;
	int		fd;

	fd = open(name, O_RDONLY | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		ft_printf("%s : so such file or directory\n", name);
	token = create_token_file(name, fd, id);
	return (token);
}

int	next_file_tokenizer(t_env *env, char *line, int index)
{
	t_token	*token;
	int		new_index;
	char	*content;

	if (line_is_finish(line, index))
		return (index);
	index = blank_escape(line, index);
	new_index = file_detection(line, index);
	content = malloc_substrcpy(line, index, new_index);
	token = file_tokenizer(content, TOKEN_FILE);
	add_token_list(env, token);
	return (new_index);
}

int	blank_arg_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	t_arg	*arg;
	int		start;
	int		end;

	end = index;
	start = index;
	while (line[index])
	{
		if (!(is_blank_argument(env, line, index)))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	arg = arg_tokenizer(line, start, end, TOKEN_BLANK);
	add_arg_list(cmd, arg);
	return (end);
}
