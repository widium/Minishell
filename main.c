/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:02:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/06 17:58:33 by ebennace         ###   ########.fr       */
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

int is_not_NULL(char c, char d)
{
	if (c && d)
		return (1);
	return (0);
}

int	is_in_str(char *first, int i, char *second)
{
	int second_i;
	int second_size;

	second_size = ft_strlen(second);
	second_i = 0;
	while (is_not_NULL(first[i], second[second_i]) && second_i < second_size)
	{
		if (first[i] != second[second_i])
			return (0);
		// printf("%c %c\n", first[i], second[i]);
		++i;
		++second_i;
	}
	if (second_i == second_size && second[second_i] == '\0')
		return (1);
	return (0);
}

int search_string(char *str1, char *str2)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (str1[i])
	{
		if (is_in_str(str1, i, str2))
			count++;
		i++;
	}
	return (count);
}

int built_in_detection(char *str)
{
	int count = 0;

	count += search_string(str, "echo ");
	count += search_string(str, "cd ");
	count += search_string(str, "pwd ");
	count += search_string(str, "export ");
	count += search_string(str, "unset ");
	count += search_string(str, "env ");
	count += search_string(str, "exit ");
	
	return (count);
}

int main()
{
    char *str = "echo \"bonjour\" && cd .. && pwd > result.txt | echo $HOME ";
	// printf("\n\n%d\n", is_in_str(str, 0, "echo"));
	printf("nbr -> %d\n", built_in_detection(str));
    // printf("result : %s\n",ft_strnstr(str, "echo", ft_strlen("echo")));
}