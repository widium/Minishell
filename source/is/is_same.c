/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:18:38 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 18:18:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	same_name(char *first, char *second)
{
	if (same_str(first, second, ft_strlen(second)))
	{
		return (1);
	}
	return (0);
}
