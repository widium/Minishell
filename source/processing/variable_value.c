/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:47:07 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_arg_variables_value(t_env *env)
{
	t_token	*token;
	t_arg	*arg;

	token = get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token) && token_have_args(token))
		{
			arg = get_first_arg(get_class(token));
			while (arg)
			{
				if (is_arg_variable(arg))
					change_arg_variable_content(env, arg);
				arg = arg->next;
			}
		}
		token = token->next;
	}
}

void	change_arg_variable_content(t_env *env, t_arg *arg)
{
	char	*name;
	char	*value;

	name = malloc_strcpy(arg->content);
	free(arg->content);
	value = get_env_var_value_with_name(env, name);
	if (value == NULL)
	{
		ft_printf("Error : unknow variable [%s]\n", name);
		env->error_processing += 1;
	}
	else
		arg->content = malloc_strcpy(value);
	free(name);
}
