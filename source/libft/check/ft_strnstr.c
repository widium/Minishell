/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:09:20 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 17:10:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;

	i = 0;
	hay = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || little == big)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		c = 0;
		while (hay[i + c] && little[c]
			&& hay[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (hay + i);
		++i;
	}
	return (0);
}
/*
int main ()
{
	const char str[] = "aaabcabcd";
	const char find [] = "cd";
	size_t len = 8;
	printf("%s\n",strnstr(str,find, len));
	printf("%s\n",ft_strnstr(str,find, len));
}
*/
