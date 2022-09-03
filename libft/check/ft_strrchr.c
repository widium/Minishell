/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:33:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:54:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr( const char *str, int find)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char)find)
		{
			return (((char *)str + i));
		}
		i--;
	}
	return (NULL);
}

/*
int main ()
{
	char str[] = "123";
	char find = '3';
	printf("%s\n",ft_strrchr(str,(int)find));
	printf("%s\n",strrchr(str,(int)find));
}
*/
