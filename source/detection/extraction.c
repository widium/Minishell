/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:25:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 14:35:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arg_redirect_extraction(t_env *env, t_token *token, char *line, int index)
{
	if (is_token_heredoc(token))
	{
		index = limiter_extraction(get_class(token), line, ++index);
	}
	else if (is_token_basic_redirection(token))
	{
		index = next_file_tokenizer(env, line, ++index);
	}
	return (index);
}

// int	variables_tokenization(t_cmd *cmd, char *line, int index)
// {
// 	t_arg	*arg;
// 	int		start;
// 	int		end;

// 	end = index;
// 	start = index;
// 	if (line[index + 1] == '$')
// 		return (index + 1);
// 	index++;
// 	while (line[index])
// 	{
// 		if (is_variable_delimiter(line, index))
// 		{
// 			end = index - 1;
// 			break ;
// 		}
// 		index++;
// 	}
// 	if (is_variable_delimiter(line, index))
// 		end = index - 1;
// 	arg = arg_tokenizer(line, start + 1, end, TOKEN_VARIABLE);
// 	add_arg_list(cmd, arg);
// 	return (end);
// }

int	word_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	char	*content;
	int		start;
	int		end;

	start = index;
	end = index;
	while (line[index])
	{
		if (is_word_argument_separator(env, line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (!(is_word_argument_separator(env, line, index)))
		end = index -1;
	content = malloc_substrcpy(line, start, end);
	word_arg_tokenizer(env, cmd, content);
	return (end);
}

int	string_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	t_arg	*arg;
	int		start;
	int		end;

	start = index;
	end = index;
	while (line[index])
	{
		if (is_double_quote(line[index]) || is_variable(env, line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (!(is_double_quote(line[index])) || !(is_variable(env, line, index)))
		end = index - 1;
	arg = arg_tokenizer(line, start, end, TOKEN_STRING);
	add_arg_list(cmd, arg);
	return (end);
}

int	limiter_extraction(t_redir *redir, char *line, int index)
{
	int	new_index;
	int	start;

	start = index;
	if (is_finish(line[index]))
		return (start);
	while (line[index])
	{
		if (!(is_blank(line[index])))
		{
			new_index = limiter_detection(line, index);
			redir->limiter = malloc_substrcpy(line, index, new_index);
			return (new_index);
		}
		index++;
	}
	return (start);
}
