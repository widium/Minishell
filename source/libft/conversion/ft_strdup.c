/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:26:41 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:29:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	i++;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, i);
	return (dest);
}
/*
int main ()
{
	char src[] = "12345";
	printf("%s\n",ft_strdup(src));
	printf("%s\n",strdup(src));
}
*/
