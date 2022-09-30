/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:22:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:28:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long long int	ft_atol(const char *str)
{
	long long int	i;
	long long int	res;
	long long int	nv;

	nv = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == 45)
	{
		nv = -1;
		i++;
	}
	else if (str[i] == 43)
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * nv);
}
