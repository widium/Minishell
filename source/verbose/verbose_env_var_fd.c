/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env_var_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:19:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 19:21:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_env_var_fd(t_env *env, int fd)
{
	t_var	*var;

	(void)fd ;
	var = get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		if (var->id == VALUE)
			print_env_var_fd(var, fd);
		var = var->next;
	}
}

void	print_env_var_fd(t_var *var, int fd)
{
	(void)fd ;
	if (!var || !var->name)
		return ;
	if (!var->value)
		ft_printf_fd(fd, "%s\n", var->name);
	else
		ft_printf_fd(fd, "%s=%s\n", var->name, var->value);
}

void	print_all_env_export_var_fd(t_env *env, int fd)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		print_env_var_fd(var, fd);
		var = var->next;
	}
}
