/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:44:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 17:03:57 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *  copie string from start to nbr of char
 * 
 *  ex : "je suis la"
 * 	start = 1 // e
 *  len = 3 // u
 *  result = e su;
 * 
 **/

#include "../libft.h"

char	*ft_copie(char *dest, char *s, int i, int len)
{
	int	y;

	y = 0;
	while (y < len)
	{
		dest[y] = s[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (dest);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*dest;
	int		size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (start >= size)
		return (ft_strdup(""));
	if ((size - start) < len)
		len = (size - start);
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_copie(dest, str, start, len));
}
/*
int main ()
{
	char s[] = "123456789erhderahqwatghtehyq3TWYHEATJWJ65HY4T3QWRAfgedahetnj5";
	int start = 150;
	int len = 6;
	printf("%s\n",ft_substr(s, start, len));

}
*/
