/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:06:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:29:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size )
{
	int	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < (int)size)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main ()
{
	char dest[22] = "";
	char src[] = "test basic du memcpy !";
	size_t size  = 22;
	printf("%s\n",ft_memcpy(dest,src,size));
	printf("%s\n",memcpy(dest,src,size));
}
*/
