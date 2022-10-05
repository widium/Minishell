/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:23:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_all_env_var(t_env *env)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		if (var->id == VALUE)
			print_env_var(var);
		var = var->next;
	}
}

void	print_all_env_export_var(t_env *env)
{
	t_var	*var;

	var = get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		print_env_var(var);
		var = var->next;
	}
}

void	print_env_var(t_var *var)
{
	if (!var || !var->name)
		return ;
	if (!var->value)
		ft_printf("%s\n", var->name);
	else
		ft_printf("%s=%s\n", var->name, var->value);
}

// void	print_all_env_var_struct(t_env *env)
// {
// 	t_var	*var;

// 	var = get_first_env_var(env);
// 	if (!var)
// 		return ;
// 	while (var)
// 	{
// 		print_env_var_struct(var);
// 		var = var->next;
// 	}
// }

// void	print_env_var_struct(t_var *var)
// {
// 	ft_printf(" ---[%s]---\n", var->name);
// 	ft_printf(" | type : [%d]\n", var->id);
// 	ft_printf(" | index : [%d]\n", var->index);
// 	ft_printf(" | value : [%s]\n", var->value);
// 	ft_printf(" ----------------\n");
// }
