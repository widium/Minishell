/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 09:59:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;

int	main(int argc, char **argv, char **env_var)
{
	t_env	*env;
	char	**env_variable;

	(void)argc;
	(void)argv;
	env_variable = malloc_strcpy_array(env_var);
	env = init_env(env_variable);
	ask_verbose(env);
	prompt(env);
	remove_all(env);
}
