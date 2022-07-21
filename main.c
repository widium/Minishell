/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 21:32:24 by ebennace         ###   ########.fr       */
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
	int index = 0;
	
    char *line = " << STOP";
	printf("[%c] Result : is_after_redirect %d\n",line[4], is_after_redirect(line, 4));
    printf("[%c] Result : is_file %d\n",line[4], is_file(line, 4));

	char *line3 = "cd .. && echo -e $HOME | cat -e | wc -l > result.txt && cat ft_*.c | wc -l >> result.txt && wc -l << STOP";
	
	printf("[%c] Result 1 : is_after_redirect %d\n",line3[101], is_after_redirect(line3, 101));
    printf("[%c] Result 1 : is_file %d\n",line3[101], is_file(line3, 101));
	
	char *line2 = " << STOP";
	printf("[%c] Result 2 : is_after_redirect %d\n",line2[4], is_after_redirect(line2, 4));
    printf("[%c] Result 2 : is_file %d\n",line2[4], is_file(line2, 4));
}