/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:16:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:04:13 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_variable(t_env *env, char *line, int i)
{
	char	*name;

	if (is_variable_word(line, i))
	{
		name = variable_name_extraction(line, ++i);
		if (!name)
			return (0);
		if (variable_exist(env, name))
		{
			free(name);
			return (1);
		}
		free(name);
	}
	return (0);
}

int	is_variable_word(char *line, int i)
{
	if (line[i] == '$' && !(is_blank(line[i + 1]))
		&& !(is_finish(line[i + 1])) && !(is_quote(line[i + 1]))
		&& !(is_separator(line, i + 1)))
		return (1);
	return (0);
}

int	variable_exist(t_env *env, char *name)
{
	t_var	*var;

	var = get_env_var_with_name(env, name);
	if (!var)
		return (0);
	if (same_name(var->name, name))
		return (1);
	return (0);
}

int	is_valide_variable(t_env *env, char *word)
{
	if (is_variable_word(word, 0) && !(is_variable(env, word, 0)))
		return (0);
	return (1);
}

char	*variable_name_extraction(char *line, int index)
{
	int		start;
	int		end;
	char	*name;

	end = index;
	start = index;
	if (line[index] == '$')
		return (NULL);
	index++;
	while (line[index])
	{
		if (is_variable_delimiter(line, index))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	if (is_variable_delimiter(line, index))
		end = index - 1;
	name = malloc_substrcpy(line, start, end);
	return (name);
}
