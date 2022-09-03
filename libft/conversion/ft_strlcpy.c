/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:36:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:29:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		srcsize;

	n = (unsigned int)n;
	i = 0;
	srcsize = ft_strlen((char *)src);
	if (n)
	{
		while (src[i] != '\0' && (i + 1 < n))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (srcsize);
}

/*
int main ()
{
	char src[100] = "BBBB";
	char dest[0xF00];

	unsigned int n = 25;
	printf("%zu\n",ft_strlcpy(dest,src,n));
	printf("%zu\n", strlcpy(dest,src,n));
	printf("%s", dest);
}*/
