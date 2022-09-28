/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:53:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:57:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	disconect_arg(t_arg *current_arg)
{
	t_arg	*arg_prev;
	t_arg	*arg_next;

	arg_prev = current_arg->prev;
	arg_next = current_arg->next;
	if (arg_prev)
		arg_prev->next = arg_next;
	if (arg_next)
		arg_next->prev = arg_prev;
	current_arg->next = NULL;
	current_arg->prev = NULL;
}

void	disconect_line(t_line *current_line)
{
	t_line	*line_prev;
	t_line	*line_next;

	line_prev = current_line->prev;
	line_next = current_line->next;
	if (line_prev)
		line_prev->next = line_next;
	if (line_next)
		line_next->prev = line_prev;
	current_line->next = NULL;
	current_line->prev = NULL;
}

void	disconect_env_var(t_env *env, t_var *var)
{
	t_var	*var_prev;
	t_var	*var_next;

	var_prev = var->prev;
	var_next = var->next;
	if (var->index == 0)
	{
		disconect_env_var_first(env, var, var_next);
		return ;
	}
	if (var_prev)
		var_prev->next = var_next;
	if (var_next)
		var_next->prev = var_prev;
	var->next = NULL;
	var->prev = NULL;
}

void	disconect_env_var_first(t_env *env, t_var *var, t_var *var_next)
{
	if (!var_next)
		env->first_var = NULL;
	else
	{
		env->first_var = var_next;
		var_next->prev = NULL;
	}
	var->next = NULL;
	var->prev = NULL;
}

void	disconect_token(t_token *token)
{
	token->next = NULL;
	token->prev = NULL;
}
