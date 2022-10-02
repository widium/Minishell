/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:03:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 19:22:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	export_built_in(t_cmd *cmd, t_env *env)
{
	char	*name;
	char	*value;
	int		id;

	if (!cmd->arg)
	{
		print_all_env_export_var_fd(env, cmd->fd_out);
		return (0);
	}
	name = get_export_variable_name(cmd->arg);
	if (!name)
	{
		ft_putstr_fd("export: not a valid identifier\n", 1);
		return (1);
	}
	value = get_env_variable_value(cmd->arg);
	id = assign_env_var_id(value);
	change_or_create_var(env, name, value, id);
	return (0);
}

void	change_or_create_var(t_env *env, char *name, char *value, int id)
{
	t_var	*var;

	if (variable_exist(env, name))
	{
		change_env_var_value_with_name(env, name, value);
		free(name);
	}
	else
	{
		var = init_env_variable(name, value, id);
		add_new_env_variable(env, var);
	}
}

int	assign_env_var_id(char *value)
{
	if (!value)
		return (NONE_VALUE);
	return (VALUE);
}

int	unset(t_cmd *cmd, t_env *env)
{
	t_var	*var;
	char	*name;

	if (!cmd->arg)
		return (0);
	name = get_variable_name(cmd->arg);
	var = get_env_var_with_name(env, name);
	if (var)
	{
		remove_and_disconect_env_var(env, var);
	}
	free(name);
	return (0);
}
