/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 18:20:28 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	built_in_execution(t_env *env, t_cmd *cmd)
{
	int	status;

	status = -1;
	if (is_echo(cmd))
		status = echo(cmd);
	else if (is_cd(cmd))
		status = cd(cmd, env);
	else if (is_env(cmd))
		status = env_built_in(cmd, env);
	else if (is_export(cmd))
		status = export_built_in(cmd, env);
	else if (is_unset(cmd))
		status = unset(cmd, env);
	else if (is_pwd(cmd))
		status = pwd(cmd);
	else if (is_exit(cmd))
	{
		status = 0;
		exit_built_in(cmd, env);
	}
	return (status);
}
