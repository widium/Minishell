/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:52:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 11:53:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_home_path(t_env *env)
{
	char	*value;
	char	*path;

	value = get_env_var_value_with_name(env, "HOME");
	path = malloc_strcpy(value);
	return (path);
}

char	*get_current_path(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		perror("getcwd() Error\n");
	return (path);
}

char	*get_last_path(t_env *env)
{
	char	*last_path;
	char	*path;

	last_path = get_env_var_value_with_name(env, "PWD");
	path = malloc_strcpy(last_path);
	return (path);
}
