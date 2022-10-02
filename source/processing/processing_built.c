/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_built.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:47:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 16:42:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	processing_built_in(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;

	token = get_first_token_built_in(env);
	while (token)
	{
		cmd = get_class(token);
		choose_processing_built_in(env, cmd);
		token = get_next_token_built_in(token);
	}
}

void	choose_processing_built_in(t_env *env, t_cmd *cmd)
{
	if (is_cd(cmd))
		processing_cd(env, cmd);
	else if (is_echo(cmd))
		processing_echo(cmd);
	else if (is_exit(cmd))
		processing_exit(cmd);
}

void	processing_exit(t_cmd *cmd)
{
	int	nbr;

	nbr = get_number_args(cmd);
	if (nbr > 2)
	{
		ft_putstr_fd("Too many argument\n", 1);
		remove_all_arg(cmd);
	}
}

void	processing_echo(t_cmd *cmd)
{
	t_arg	*arg;

	if (cmd_have_arg_flags(cmd))
	{
		arg = get_cmd_flags(cmd);
		cmd->flags = malloc_strcpy(arg->content);
		if (is_arg_blank(arg->next))
			remove_arg_in_cmd(cmd, arg->next);
		remove_arg_in_cmd(cmd, arg);
	}
}

void	processing_cd(t_env *env, t_cmd *cmd)
{
	if (!(cmd_have_args(cmd)))
		cmd->arg = get_home_path(env);
}
