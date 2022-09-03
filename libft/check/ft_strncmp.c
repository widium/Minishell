/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:58:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/22 12:31:37 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *first, const char *second, size_t size)
{
	int	i;

	i = 0;
	if ((int)size < 0)
		size = ft_strlen(first);
	while ((unsigned char)(first[i]) != '\0'
	&& (unsigned char)(second[i]) != '\0' && i < (int)size)
	{
		if ((unsigned char)(first[i]) != (unsigned char)(second[i]))
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	if (i != (int)size)
		return ((unsigned char)first[i] - (unsigned char)second[i]);
	return ((unsigned char)first[i - 1] - (unsigned char)second[i - 1]);
}

// int	ft_strncmp(const char *first, const char *second, size_t size)
// {
// 	int	i;

// 	i = 0;
// 	if ((int)size < 0)
// 		size = ft_strlen(first);
// 	while (first[i] && second[i] && i < (int)size)
// 	{
// 		if (first[i] != second[i])
// 			return (first[i] - second[i]);
// 		i++;
// 	}
// 	if (i != (int)size)
// 		return (first[i] - second[i]);
// 	return (first[i - 1] - second[i - 1]);
// }
/*
int main ()
{
	char first[] = "1234";
	char second[] = "1236";
	size_t n = -1;
	printf("%i\n",ft_strncmp(first,second,n));
	printf("%i\n",strncmp(first,second,n));

}
*/
