/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:56:25 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 08:42:59 by ebennace         ###   ########.fr       */
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

char	*ft_strjoin_free_first(char *s1, char *s2)
{
	char	*complete;

	complete = ft_strjoin(s1, s2);
	free(s1);
	s1 = NULL;
	return (complete);
}

char	*ft_strjoin_free_second(char *s1, char *s2)
{
	char	*complete;

	complete = ft_strjoin(s1, s2);
	free(s2);
	s2 = NULL;
	return (complete);
}

char	*ft_strjoin_free_all(char *s1, char *s2)
{
	char	*complete;

	complete = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (complete);
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
