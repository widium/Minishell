/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:45:44 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 21:08:43 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_pipe(char *line, int i)
{
   if (line[i - 1] != '|' && line[i] == '|' && line[i + 1] != '|')
        return (1);
    return (0); 
}

int is_output_chevrons(char *line, int i)
{
    if (line[i - 1] != '>' && line[i] == '>' && line[i + 1] != '>')
        return (1);
    return (0);
}

int is_input_chevrons(char *line, int i)
{
    if (line[i - 1] != '<' && line[i] == '<' && line[i + 1] != '<')
        return (1);
    return (0);
}

int is_append_chevrons(char *line, int i)
{
    if ((line[i-1] != '>' && line[i] == '>' && line[i+1] == '>' && line[i+2] != '>') || 
        (line[i-2] != '>' && line[i - 1] == '>' && line[i] == '>' && line[i + 1] != '>'))
        return (1);
    return (0);
}

int is_heredoc(char *line, int i)
{
    if ((line[i-1] != '<' && line[i] == '<' && line[i+1] == '<' && line[i+2] != '<') ||
        (line[i-2] != '<' && line[i - 1] == '<' && line[i] == '<' && line[i+1] != '<'))
        return (1);
    return (0);
}

int is_redirection(char *line, int i)
{
    if (is_pipe(line, i) || is_output_chevrons(line, i) ||
            is_input_chevrons(line, i) || is_append_chevrons(line, i) || is_heredoc(line , i))
        return (1);
    return (0);
}

int is_file_redirection(char *line, int i)
{
    if (is_output_chevrons(line, i) || is_input_chevrons(line, i) ||
        is_append_chevrons(line, i))
        return (1);
    return (0);
}