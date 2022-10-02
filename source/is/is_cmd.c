/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:26:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 18:28:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_bin(t_env *env, char *word)
{
	char	**bins;

	bins = get_env_bins(env);
	if (!bins)
		return (0);
	else if (test_absolute_bin_access(word) || test_bin_access(bins, word))
	{
		free_array(bins);
		return (1);
	}
	free_array(bins);
	return (0);
}

int	is_cmd(t_env *env, char *word)
{
	if (is_bin(env, word) || is_built_in(word))
		return (1);
	return (0);
}

int	is_built_in(char *content)
{
	if (same_str(content, "echo", ft_strlen(content)))
		return (1);
	if (same_str(content, "cd", ft_strlen(content)))
		return (1);
	if (same_str(content, "pwd", ft_strlen(content)))
		return (1);
	if (same_str(content, "env", ft_strlen(content)))
		return (1);
	if (same_str(content, "export", ft_strlen(content)))
		return (1);
	if (same_str(content, "unset", ft_strlen(content)))
		return (1);
	if (same_str(content, "exit", ft_strlen(content)))
		return (1);
	return (0);
}

int	is_unset(t_cmd *cmd)
{
	if (same_str("unset", cmd->content, ft_strlen("unset")))
		return (1);
	return (0);
}

int	is_exit(t_cmd *cmd)
{
	if (same_str("exit", cmd->content, ft_strlen("exit")))
		return (1);
	return (0);
}
