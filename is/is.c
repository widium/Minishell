/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 15:35:27 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_not_null(char c, char d)
{
	if (c && d)
		return (1);
	return (0);
}

int	is_null(char *line)
{
	if (line == NULL)
		return (1);
	return (0);
}

int	is_value_null(char *value)
{
	if (value[0] == '\0')
		return (1);
	return (0);
}

int	is_back_slash(char c)
{
	if (c == '\\')
		return (1);
	return (0);
}

int	is_word(t_env *env, char *line, int i)
{
	if (!(is_quote(line[i])) && !(is_blank(line[i]))
		&& !(is_separator(line, i))
		&& !(is_variable(env, line, i)) && line[i] != '$')
		return (1);
	return (0);
}
