/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 16:53:42 by ebennace         ###   ########.fr       */
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
	env->verbose = 1;
    prompt(env);
	remove_all(env);
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
	
// 	char **env_variable = malloc_strcpy_array(env);
// 	char **ret = ft_split(env_variable[0], '=');
// 	print_array(ret);

// }