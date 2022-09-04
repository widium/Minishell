/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/04 16:10:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env_var)
{
	t_env	*env;
	char **env_variable;
	

	env_variable = malloc_strcpy_array(env_var);
	env = init_env(env_variable);
	ask_verbose(env);
	prompt(env);
	remove_all(env);
}

void ask_verbose(t_env *env)
{
	char answer;
	
	printf("Minishell mode verbose [Y/N] ?");
	scanf("%c", &answer);
	if (answer == 'Y')
	{
		printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	else if (answer == 'N')
		env->verbose = 0;
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

// int main(int argc, char **argv, char **env)
// {
//     char *test = "salut";
// 	char *new = malloc_substrcpy(test, 1, 2);
// 	printf("new :[%s]\n", new);
// }