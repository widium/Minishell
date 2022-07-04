/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/04 17:11:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	main(void)
// {
// 	t_env	*env;
	
// 	env = init_env();
// 	open_files(env);
// 	prompt(env);

// }

int main()
{
    char *str = "echo salut moi c'est eddie | wc -l";
	word_extraction(str);
	// char *ret = double_quotes_extraction(str);
	// char *ret2 = single_quotes_extraction(str);
    // printf("return : %s\n", ret);
	// printf("return : %s\n", ret2);
}
