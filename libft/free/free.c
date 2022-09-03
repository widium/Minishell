/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:11:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:39:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_array(char **array)
{
	int	i;

	if (!(array))
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

// void	free_cmd(t_command *cmd)
// {
// 	t_command	*iter;

// 	while (cmd->next_cmd)
// 	{
// 		iter = cmd->next_cmd;
// 		//free all malloc in struct
// 		free(cmd);
// 		cmd = iter;
// 	}
// 	free(cmd);
// }