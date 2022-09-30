/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:30:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 18:00:41 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_argument(char *line, int i)
{
	if (!(is_separator(line, i)) && !(is_blank(line[i])))
		return (1);
	return (0);
}

int	is_flags(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (line[i] == '-' && !(is_blank(line[i + 1])) && line[i + 1] == 'n')
		return (1);
	return (0);
}
