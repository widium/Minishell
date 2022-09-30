/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:35:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:19:57 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_list_of_bins(t_env *env)
{
	char	**bins;
	char	*path;

	path = get_env_var_value_with_name(env, "PATH");
	bins = ft_split(path, ':');
	return (bins);
}

int	test_bin_access(char **bins, char *word)
{
	int		i;
	char	*path;

	i = 0;
	while (bins[i])
	{
		path = ft_strjoin_char(bins[i], word, '/');
		if (access(path, X_OK & F_OK) == 0)
		{
			free(path);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}

int	test_absolute_bin_access(char *path)
{
	if (access(path, X_OK & F_OK) == 0)
		return (1);
	return (0);
}
