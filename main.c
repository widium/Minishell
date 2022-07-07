/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 14:55:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_env	*env;
	
	env = init_env();
	open_files(env);
	prompt(env);

}

// int main()
// {
//     char *str = "echo \"bonjour\" && cd .. && pwd > result.txt | echo $HOME ";
// 	// printf("\n\n%d\n", is_in_str(str, 0, "echo"));
// 	built_in_detection(str);
//     // printf("result : %s\n",ft_strnstr(str, "echo", ft_strlen("echo")));
// }