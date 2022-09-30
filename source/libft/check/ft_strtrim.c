/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:24:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:35:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_start(char *s1, char *set)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start] == set[i])
		{
			start++;
			i = -1;
		}
		i++;
	}
	return (start);
}

int	ft_end(char *s1, char *set)
{
	int	i;
	int	start;

	start = ft_strlen(s1);
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start - 1] == set[i])
		{
			start--;
			i = -1;
		}
		i++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (!(s1) || !(set))
		return (NULL);
	start = ft_start((char *)s1, (char *)set);
	end = ft_end((char *)s1, (char *)set);
	return (ft_substr((char *)s1, start, end - start));
}
/*
int main ()
{
	char s1[] = "   xxxtripouille   xxx";
	char set[] = " x";
	printf("%i\n",ft_start(s1, set));
	printf("%i\n",ft_end(s1, set));
	printf("%s\n",ft_strtrim(s1, set));
}
*/
