/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/18 18:47:29 by ebennace         ###   ########.fr       */
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
	// env->verbose = 1;
    // prompt(env);
	// remove_all(env);
}

// void array_to_list(t_variable *variables)
// {
// 	t_env_var *var;
// 	char **env_variables;
// 	int index;
// 	char *name;
// 	char *value;

// 	var = init_env_variable();
// 	env_variables = variables->variables;
	
// 	// add_variables_list()
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