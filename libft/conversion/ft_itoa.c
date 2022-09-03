/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:02:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:29:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	ft_inverse(int n, int *p)
{
	unsigned int	u_n;

	if (n < 0)
	{
		*p = 1;
		u_n = (unsigned int)(n * -1);
	}
	else
		u_n = (unsigned int)(n);
	return (u_n);
}

char	*ft_cop(char *str, int nb, int i)
{
	unsigned int	u_nb;

	if (nb < 0)
	{
		u_nb = (unsigned int)(nb * -1);
		str[0] = 45;
	}
	else
		u_nb = (unsigned int)(nb);
	while (u_nb > 0)
	{
		str[--i] = 48 + (u_nb % 10);
		u_nb = u_nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	u_n;
	char			*nbr;

	i = 0;
	u_n = ft_inverse(n, &i);
	if (n == 0)
		return (ft_strdup("0"));
	while (u_n > 0)
	{
		u_n = u_n / 10;
		i++;
	}
	nbr = ft_calloc((i + 1), sizeof(char));
	if (!nbr)
		return (NULL);
	nbr = ft_cop(nbr, n, i);
	return (nbr);
}
/*
int main ()
{
	int n = -2;
	//char str[] = "aaa0aa";

	printf("%s\n",ft_itoa(n));
	//printf("%s\n",ft_copie(str, n));
}
*/
