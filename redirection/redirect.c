/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:10:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/22 14:52:27 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int type_of_redirect(char *content)
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

int recover_limiter(t_redirection *redir, char *line, int index)
{
    int new_index;
    int start;
    char *limiter;
    
    start = index;
    index++;
    while(line[index])
    {
        if (!(is_blank(line[index])))
        {
            new_index = word_detection(line, index);
            redir->limiter = ft_substr(line, index, (new_index - index) + 1);
            return (new_index);
        }
        index++;
    }
    return (start);
}