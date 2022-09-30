/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_basic_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:32:17 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 14:33:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_output_chevrons(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (line[i] == '>' && line[i + 1] != '>')
		return (1);
	return (0);
}

int	is_input_chevrons(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if (line[i] == '<' && line[i + 1] != '<')
		return (1);
	return (0);
}

int	is_append_chevrons(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if ((line[i] == '>' && line[i + 1] == '>'))
		return (1);
	return (0);
}

int	is_heredoc(char *line, int i)
{
	if (index_is_over_flow(line, i))
		return (0);
	if ((line[i] == '<' && line[i + 1] == '<'))
		return (1);
	return (0);
}
