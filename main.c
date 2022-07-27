/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:52:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env_path)
{
	t_env	*env;
	char **variables;

	variables = malloc_strcpy_array(env_path);
	env = init_env(variables);
	open_files(env);
	prompt(env);

}


// int main(int argc, char **argv, char **env)
// {
// 	int *c = malloc(10000);
// 	my_free(c);
// 	my_free(c);
// }