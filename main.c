/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/13 18:31:52 by ebennace         ###   ########.fr       */
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
// 	int index = 0;
	
//     char *line = "echo \"bo|jour\" | echo \"salut\"";
	
// 	while (line[index])
// 	{
// 		printf("%d : %c --> Return : %d\n", index, line[index], is_in_quote(line, index));
// 		index++;
// 	}
//     // printf("result : %s\n",ft_strnstr(str, "echo", ft_strlen("echo")));
// }