/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:21:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:30:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../minishell.h"

int	check_error_built_in(t_cmd *cmd)
{
	int	result;

	result = 0;
	if (is_cd(cmd))
		result += check_error_cd(cmd);
	return (0);
}

int	check_error_echo(t_cmd *cmd)
{
	int	nb_arg;
	int	result;

	result = 0;
	return (result);
}

int	check_error_cd(t_cmd *cmd)
{
	int	nb_arg;
	int	result;

	result = 0;
	nb_arg = get_number_args(cmd);
	if (nb_arg > 1)
	{
		result++;
		printf("cd : too many arguments.\n");
	}
	return (result);
}
