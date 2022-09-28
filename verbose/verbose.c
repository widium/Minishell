/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:50:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:35:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ask_verbose(t_env *env)
{
	char	answer;

	printf("Minishell mode verbose [Y/N] ?");
	scanf("%c", &answer);
	if (answer == 'Y' || answer == 'y')
	{
		printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	else if (answer == 'N' || answer == 'n')
		env->verbose = 0;
}

void	print_detection(char *line, int start, int end, int token)
{
	printf("DETECTION : [");
	while (line[start] && start <= end)
	{
		printf("%c", line[start]);
		start++;
	}
	printf("]\n");
}
