/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 19:16:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(int argc, char **argv, char **env_var)
// {
// 	t_env	*env;
// 	char **env_variable;
	

// 	env_variable = malloc_strcpy_array(env_var);
// 	env = init_env(env_variable);
// 	// ask_verbose(env);
// 	env->verbose = 1;
// 	prompt(env);
// 	remove_all(env);
// }

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

int main(int argc, char **argv, char **env)
{
    char **vars = malloc_strcpy_array(env);
	char *var = "A=123";
	char **new;

	new = ft_arrayjoin_str(vars, var, ft_strlen_array(vars));
	
    printf("len OLD : [%d]\n", ft_strlen_array(vars));
    printf("len NEW : [%d]\n", ft_strlen_array(new));
	print_array_fd(new, 1);
}