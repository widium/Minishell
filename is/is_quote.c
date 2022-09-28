/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:27:11 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:29:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int	is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (is_double_quote(c) || is_single_quote(c))
		return (1);
	return (0);
}
