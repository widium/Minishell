/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:09:49 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 15:29:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int ch)
{
	if (ch >= 97 && ch <= 122)
		return (ch - 32);
	return (ch);
}

/*int main ()
{
	int ch = 'g';
	printf("%c",ft_toupper(ch));
}
*/
