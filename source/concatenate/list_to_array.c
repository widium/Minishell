/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:24:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 08:45:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	size_of_cmd_list(t_cmd *cmd)
{
	t_arg	*arg;
	int		i;

	arg = get_first_arg(cmd);
	i = 0;
	while (arg)
	{
		i++;
		arg = arg->next;
	}
	return (i);
}

int	size_of_var_list(t_env *env)
{
	t_var	*var;
	int		i;

	var = get_first_env_var(env);
	i = 0;
	while (var)
	{
		i++;
		var = var->next;
	}
	return (i);
}

char	**cmd_list_to_array(t_cmd *cmd)
{
	t_arg	*arg;
	char	**complete;
	int		i;

	i = 0;
	if (!(cmd->first_arg))
		return (NULL);
	arg = get_first_arg(cmd);
	if (arg->content == NULL)
		return (NULL);
	complete = malloc(sizeof(char *) * (size_of_cmd_list(cmd) + 1));
	while (arg)
	{
		complete[i] = malloc_strcpy(arg->content);
		arg = arg->next;
		i++;
	}
	remove_all_arg(cmd);
	complete[i] = NULL;
	return (complete);
}

char	**variable_list_to_array(t_env *env)
{
	t_var	*var;
	char	**complete;
	int		i;

	i = 0;
	if (!(env->first_var))
		return (NULL);
	var = get_first_env_var(env);
	if (!var)
		return (NULL);
	complete = malloc(sizeof(char *) * (size_of_var_list(env) + 1));
	while (var)
	{
		if (!var->value)
			complete[i] = ft_strjoin_char(var->name, "", '=');
		else
			complete[i] = ft_strjoin_char(var->name, var->value, '=');
		var = var->next;
		i++;
	}
	complete[i] = NULL;
	return (complete);
}

char	*cmd_list_to_string(t_cmd *cmd)
{
	t_arg	*arg;
	char	*complete;

	if (!(cmd_have_args(cmd)))
		return (NULL);
	arg = get_first_arg(cmd);
	if (arg->content == NULL)
		return (NULL);
	complete = malloc_strcpy(arg->content);
	arg = arg->next;
	while (arg)
	{
		complete = ft_strjoin_free_first(complete, arg->content);
		arg = arg->next;
	}
	remove_all_arg(cmd);
	return (complete);
}
