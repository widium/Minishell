/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 15:15:55 by ebennace         ###   ########.fr       */
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
// 	char *ret = ft_strjoin_space(argv[1], argv[2]);
// 	printf("%s\n", ret);
// }