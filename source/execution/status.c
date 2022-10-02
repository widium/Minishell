/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:56:26 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:30:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	get_last_status(int bin_status, int ret_built_in)
{
	if (ret_built_in == -1)
		return (bin_status);
	else if (bin_status == -1)
		return (ret_built_in);
	return (0);
}

int	convert_status_process_value(int status)
{
	if (WIFSIGNALED(status))
		status = WEXITSTATUS(status);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}

void	update_variable_status_process(t_env *env, int status)
{
	t_var	*var;
	char	*value;

	value = ft_itoa(status);
	if (!value)
		return ;
	var = get_env_var_with_name(env, "?");
	if (!var)
	{
		free(value);
		return ;
	}
	change_env_var_value(var, value);
}
