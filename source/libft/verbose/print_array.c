/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:07:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	print_array_back_slash(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

void	print_array(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_printf("{%s}", str[i]);
		i++;
	}
}

void	print_array_fd(char **str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i], fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}

void	print_array_index(char **str, int index)
{
	if (!str)
		return ;
	while (str[index])
	{
		ft_printf("%s ", str[index]);
		index++;
	}
}

void	print_str_index(char *str, int i)
{
	while (str[i])
	{
		ft_printf("%c", str[i]);
		i++;
	}
	ft_printf("\n");
}
