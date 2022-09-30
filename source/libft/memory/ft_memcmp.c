/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:35:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:35:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

int	ft_memcmp( const void *str, const void *str2, size_t size )
{
	int	i;

	i = 0;
	while (i < (int)size)
	{
		if (!(((char *)str)[i] == ((char *)str2)[i]))
			return (((unsigned char *)str)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	i--;
	return (((unsigned char *)str)[i] - ((unsigned char *)str2)[i]);
}
/*
int main ()
{
	char pointer1[] = "\xff\xaa\xde\xffMACOSX\xff";
	char pointer2[] = "\xff\xaa\xde\x02";
	size_t size = 8;
	printf("%i\n",ft_memcmp(pointer1,pointer2,size));
	printf("%i\n",memcmp(pointer1,pointer2,size));

}
*/
