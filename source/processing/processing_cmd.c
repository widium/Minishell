/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:16:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	processing_cmd(t_env *env)
{
	processing_built_in(env);
	processing_cmd_args(env);
	processing_bin(env);
	if (env->verbose == 1)
	{
		ft_printf("=== Processing Command ===\n");
		print_all_cmd_info(env);
		ft_printf("=========\n");
	}
}

void	processing_cmd_args(t_env *env)
{
	get_arg_variables_value(env);
	concatenate_cmd_args(env);
}

void	processing_bin(t_env *env)
{
	t_cmd	*cmd;
	t_token	*token;
	char	**bins;

	bins = get_list_of_bins(env);
	token = get_first_token_cmd(env);
	while (token)
	{
		cmd = get_class(token);
		if (is_cmd_bin(cmd))
		{
			setup_bin_path(cmd, bins);
			setup_bin_args(cmd, bins);
		}
		token = get_next_token_cmd(token);
	}
	free_array(bins);
}
