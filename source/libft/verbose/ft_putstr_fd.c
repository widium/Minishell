/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:04:33 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 16:51:00 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!(str))
		return ;
	i = ft_strlen(str);
	write(fd, str, i);
}
/*
int main ()
{
	int fd = 1;
	char str[] = "\tsalut";

	ft_putstr_fd(str, fd);
}
*/
