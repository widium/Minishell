/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 08:41:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env_variable_value(char *variable)
{
	int		i;
	int		start;
	int		end;
	char	*value;

	i = 0;
	if (!variable)
		return (NULL);
	while (variable[i])
	{
		if (variable[i] == '=' && !(is_blank(variable[i + 1])))
		{
			start = i + 1;
			end = ft_strlen(variable);
			value = malloc_substrcpy(variable, start, end);
			if (is_value_null(value))
			{
				free(value);
				return (NULL);
			}
			return (value);
		}
		i++;
	}
	return (NULL);
}

char	*get_variable_name(char *variable)
{
	int		index;
	int		start;
	int		end;
	char	*name;

	index = 0;
	start = 0;
	if (!variable)
		return (NULL);
	while (variable[index])
	{
		if (variable[index] == '=')
		{
			end = index - 1;
			name = malloc_substrcpy(variable, start, end);
			return (name);
		}
		index++;
	}
	end = index;
	name = malloc_substrcpy(variable, start, end);
	return (name);
}

char	*get_export_variable_name(char *variable)
{
	int		index;
	int		start;
	int		end;
	char	*name;

	index = 0;
	start = 0;
	if (!variable)
		return (NULL);
	while (variable[index])
	{
		if (is_blank(variable[index]))
			return (NULL);
		else if (variable[index] == '=')
		{
			end = index - 1;
			name = malloc_substrcpy(variable, start, end);
			return (name);
		}
		index++;
	}
	end = index;
	name = malloc_substrcpy(variable, start, end);
	return (name);
}
