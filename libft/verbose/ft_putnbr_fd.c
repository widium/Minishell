/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:59:48 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/22 14:03:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	char			c;

	c = '-';
	nb = n;
	if (n < 0)
	{
		write(fd, &c, 1);
		nb = n * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	c = 48 + nb % 10;
	write (fd, &c, 1);
}
/*
int main ()
{
	int n = -42;
	int fd = 1;
	ft_putnbr_fd(n, fd);
}*/
