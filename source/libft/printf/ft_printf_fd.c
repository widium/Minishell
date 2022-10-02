/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 19:00:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 19:26:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../libft.h"

void	count_putstr_fd(char *str, int *count, int fd)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[i])
	{
		count_putchar_fd(str[i], count, fd);
		i++;
	}
}

void	count_putnbr_fd(int number, int *count, int fd)
{
	unsigned int	nbr;

	if (number < 0)
	{
		count_putchar_fd('-', count, fd);
		nbr = (unsigned int)number * -1;
	}
	else
		nbr = (unsigned int)number;
	if (nbr >= 10)
	{
		count_putnbr_fd(nbr / 10, count, fd);
		count_putnbr_fd(nbr % 10, count, fd);
	}
	else
		count_putchar_fd(nbr + '0', count, fd);
}

void	count_puthexa_fd(unsigned int nbr, int *count, int fd)
{
	char	*alphabet;

	alphabet = "0123456789abcdef";
	if (nbr >= 16)
	{
		count_puthexa_fd(nbr / 16, count, fd);
		count_puthexa_fd(nbr % 16, count, fd);
	}
	else
		count_putchar_fd(alphabet[nbr], count, fd);
}

static int	detect_type(va_list arg, const char *str, int index, int fd)
{
	int	count;

	count = 0;
	if (str[index] == 's')
		count_putstr_fd(va_arg(arg, char *), &count, fd);
	else if (str[index] == 'd')
		count_putnbr_fd(va_arg(arg, int), &count, fd);
	else if (str[index] == 'x')
		count_puthexa_fd(va_arg(arg, unsigned int), &count, fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	arg;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			ret += detect_type(arg, str, ++i, fd) - 1;
		else
			count_putchar_fd(str[i], &ret, fd);
		i++;
	}
	va_end(arg);
	return (ret);
}
