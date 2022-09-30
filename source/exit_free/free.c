/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:26:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:50:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env_var(t_var *var)
{
	if (var->name)
		free(var->name);
	var->name = NULL;
	if (var->value)
		free(var->value);
	var->value = NULL;
	if (var)
		free(var);
	var = NULL;
}
