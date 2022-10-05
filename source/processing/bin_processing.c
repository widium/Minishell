/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:02:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 08:43:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**append_bin_name_in_args(char **args, char *name)
{
	char	**new_args;

	if (!args)
	{	
		new_args = str_to_array(name);
	}
	else
	{
		new_args = ft_arrayjoin_str(args, name, 0);
		free_array(args);
	}
	return (new_args);
}

char	*extract_bin_name_in_path(char *path)
{
	int		index;
	char	*name;

	index = ft_strlen(path);
	while (index > 0)
	{
		if (path[index] == '/')
			break ;
		index--;
	}
	name = malloc_strcpy_after_index(path, index + 1);
	return (name);
}

void	setup_bin_path(t_cmd *cmd, char **bins)
{
	char	*command;
	char	*path;

	command = cmd->content;
	if (test_bin_access(bins, command))
	{
		path = create_path_bin(bins, command);
		cmd->bin = path;
		return ;
	}
	else if (test_absolute_bin_access(command))
	{
		cmd->bin = malloc_strcpy(command);
		return ;
	}
}

void	setup_bin_args(t_cmd *cmd, char **bins)
{
	char	*command;

	command = cmd->content;
	if (test_bin_access(bins, command))
	{
		cmd->args = append_bin_name_in_args(cmd->args, cmd->content);
		return ;
	}
	else if (test_absolute_bin_access(command))
	{
		command = extract_bin_name_in_path(command);
		free(cmd->content);
		cmd->content = command;
		cmd->args = append_bin_name_in_args(cmd->args, cmd->content);
		return ;
	}
}

char	*create_path_bin(char **bins, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (bins[i])
	{
		path = ft_strjoin_char(bins[i], cmd, '/');
		if (access(path, X_OK & F_OK) == 0)
		{
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}
