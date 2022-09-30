/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:13:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 14:22:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list		liste;
	int			i;
	int			count;

	va_start(liste, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_check_format(str, liste, i);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(liste);
	return (count);
}
