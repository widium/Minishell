/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:11:07 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:58:35 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
// le but de cette fonction la taille de la concatenation final.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	o;
	size_t	a;
	size_t	j;

	o = ft_strlen(dst);
	a = ft_strlen(src);
	j = dstsize;
	while (*dst)
	{
		dst++;
		if (j > 0)
			j--;
	}
	while (*src && j > 1)
	{
		*dst++ = *src++;
		j--;
	}
	*dst = '\0';
	if (dstsize > o)
		return (o + a);
	return (dstsize + a);
}
/*
int main ()
{
	const char src[] = "AAAAAAAAA";
	char dest[] = "B";

	size_t size = 1;
	printf("%zu\n",strlcat(dest, src, size));
	printf("%zu\n",ft_strlcat(dest, src, size));
	//printf("%s\n",dest);
}
*/
