/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:47:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:27:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_env_variables(t_env *env)
{
	char	**env_var;

	env_var = variable_list_to_array(env);
	return (env_var);
}

char	**get_env_bins(t_env *env)
{
	t_var	*var;
	char	*path;
	char	**bins;

	path = get_env_var_value_with_name(env, "PATH");
	if (!path)
		return (NULL);
	bins = ft_split(path, ':');
	return (bins);
}

t_line	*get_first_line(t_env *env)
{
	if (env->first_line)
		return (env->first_line);
	return (0);
}
