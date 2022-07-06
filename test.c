/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:55:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/06 14:22:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

int is_doublons(char *str, int i, int c)
{
    if (str[i] == c && str[i + 1] == c)
        return (1);
    return (0);
}

int main()
{
    char *str = "echo \"bonjour\" > result.txt";
    printf("result : %d\n",ft_strnstr(str, "echo", ft_strlen("echo")));
}
