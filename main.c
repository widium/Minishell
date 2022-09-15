/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/15 16:44:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env_var)
{
	t_env	*env;
	char **env_variable;

	env_variable = malloc_strcpy_array(env_var);
	env = init_env(env_variable);
	// ask_verbose(env);
	env->verbose = 0;
    prompt(env);
	remove_all(env);
}

// int main()
// {
// 	int id;

// 	id = fork();

// 	if (id == 0)
// 	{
// 		printf("nike\n");
// 	}
// 	else
// 	{
// 		wait(&id);
// 		printf("zeubi\n");
// 	}
// }

// void test(char *str, int *index)
// {

// 	while (str[*index])
// 	{
// 		ft_putchar_fd(str[*index], 1);
// 		(*index)++;
// 	}
// }

// int main(int argc, char **argv, char **env)
// {
// 	int index = 0;

// 	test("salut moi c'est eddie\n", &index);
// 	printf("index : [%d]\n", index);
	
// }