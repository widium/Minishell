/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:45:44 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:33:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_pipe(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (line[i] == '|' && line[i + 1] != '|')
		return (1);
	return (0);
}

int	is_redirection(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (is_pipe(line, i) || is_output_chevrons(line, i)
		|| is_input_chevrons(line, i) || is_append_chevrons(line, i)
		|| is_heredoc(line, i))
		return (1);
	return (0);
}

int	is_file_redirection(char *line, int i)
{
	if (is_output_chevrons(line, i) || is_input_chevrons(line, i)
		|| is_append_chevrons(line, i))
		return (1);
	return (0);
}
