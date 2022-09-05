/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:56:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 10:38:16 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cont;
	int		i;
	int		a;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1);
	a = ft_strlen(s2);
	cont = malloc((i + a + 1) * sizeof(char));
	if (!cont)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
	{
		cont[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		cont[i + a] = s2[a];
		a++;
	}
	cont[i + a] = '\0';
	return ((char *)cont);
}

char	*ft_strjoin_char(char *s1, char *s2, char c)
{
	char	*cont;
	int		i;
	int		y;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1);
	y = ft_strlen(s2);
	cont = malloc((i + y + 2) * sizeof(char));
	i = 0;
	y = 0;
	while (s1[i])
	{
		cont[i] = s1[i];
		i++;
	}
	cont[i] = c;
	while (s2[y])
	{

		cont[i + y + 1] = s2[y];
		++y;
	}
	cont[i + y + 1] = '\0';
	return (cont);
}

int ft_strlen_array(char **array)
{
	int i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**ft_arrayjoin_str(char **array, char *str, int pos)
{
	char **new_array;
	int size;
	int i;
	int y;
	
	size = ft_strlen_array(array);
	new_array = malloc(sizeof(char *)*size + 2);
	
	i = 0;
	y = 0;
	while (array[i])
	{
		if (y != pos)
		{
			new_array[y] = malloc_strcpy(array[i]);
			i++;
		}
		else
		{
			new_array[y] = malloc_strcpy(str);
		}
		y++;
	}
	new_array[y] = NULL;
	return (new_array);
	
}
/*
int main ()
{
	char s1[] = "12345";
	char s2[] = "12345";
	printf("%s\n",(char *)ft_strjoin(s1, s2));
}
*/