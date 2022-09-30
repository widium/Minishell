/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:10:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/28 09:19:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	type_of_redirect(char *content)
{
	if (is_pipe(content, 0))
		return (TOKEN_PIPE);
	else if (is_input_chevrons(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_input_chevrons(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_append_chevrons(content, 0))
		return (TOKEN_APPEND_CHEVRON);
	else if (is_output_chevrons(content, 0))
		return (TOKEN_OUTPUT_CHEVRON);
	else if (is_heredoc(content, 0))
		return (TOKEN_HERE_DOC);
	return (0);
}
