/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:08:47 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 19:09:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../libft.h"

int	ft_puthexa_max(unsigned int nb)
{
	int		i;
	int		count;
	char	*alphabet;
	char	dest[100];

	count = 0;
	i = 0;
	alphabet = "0123456789ABCDEF";
	if (nb == 0)
		count += ft_putchar('0');
	while (nb != 0)
	{
		dest[i] = alphabet[nb % 16];
		nb = nb / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		count += ft_putchar(dest[i]);
		i--;
	}
	return (count);
}

int	ft_puthexa_min(unsigned int nb)
{
	int		i;
	int		count;
	char	*alphabet;
	char	dest[100];

	count = 0;
	i = 0;
	alphabet = "0123456789abcdef";
	if (nb == 0)
		count += ft_putchar('0');
	while (nb != 0)
	{
		dest[i] = alphabet[nb % 16];
		nb = nb / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		count += ft_putchar(dest[i]);
		i--;
	}
	return (count);
}

int	ft_print(unsigned long nb, char *dest, char *alphabet, int i)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		dest[i] = alphabet[nb % 16];
		nb = nb / 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		count += ft_putchar(dest[i]);
		i--;
	}
	return (count);
}

int	ft_puthexa_long(unsigned long nb)
{
	int		i;
	int		count;
	char	*alphabet;
	char	*start;
	char	dest[100];

	count = 0;
	i = 0;
	alphabet = "0123456789abcdef";
	start = "0x";
	count = ft_putstr(start);
	if (nb == 0)
		return (count += ft_putchar('0'));
	count += ft_print(nb, dest, alphabet, i);
	return (count);
}
