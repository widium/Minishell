/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 12:56:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 07:32:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_error_token_cmd(t_token *token)
{
	t_cmd	*cmd;
	int		result;

	result = 0;
	cmd = get_class(token);
	if (is_token_cmd(token->next))
	{
		printf("Error : [Two following cmd \"%s\" && \"%s\"]\n",
			cmd->content, get_class(token->next));
		result += 1;
	}
	else if (is_token_cmd(token->prev))
	{
		printf("Error : [Two following cmd \"%s\" && \"%s\"]\n",
			get_class(token->prev), cmd->content);
		result += 1;
	}
	if (is_cmd_built_in(cmd))
	{
		result += check_error_built_in(cmd);
	}
	return (result);
}
