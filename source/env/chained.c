/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 15:17:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_variables_list(t_env *env, t_var *var)
{
	t_var	*iter;
	int		i;

	i = 0;
	if (!(env->first_var))
	{
		env->first_var = var;
		var->index = i;
	}
	else
	{
		iter = env->first_var;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		var->index = i;
		connect_var(iter, var);
	}
}

void	add_token_list(t_env *env, t_token *token)
{
	t_token	*iter;
	int		i;

	i = 1;
	if (!(env->first_token))
	{
		env->first_token = token;
		token->index = i;
	}
	else
	{
		iter = env->first_token;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		token->index = i;
		connect_token(iter, token);
	}
}

void	add_arg_list(t_cmd *cmd, t_arg *arg)
{
	t_arg	*iter;
	int		i;

	i = 1;
	if (!(cmd->first_arg))
	{
		cmd->first_arg = arg;
		arg->index = i;
	}
	else
	{
		iter = cmd->first_arg;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		arg->index = i;
		connect_arg(iter, arg);
	}
}
