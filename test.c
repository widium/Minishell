/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:55:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/13 14:55:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"


int main()
{
    char *str = "echo \"bonjour\" > result.txt";
    printf("result : %d\n",ft_strnstr(str, "echo", ft_strlen("echo")));
}
