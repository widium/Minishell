/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:50:12 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 20:14:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_file(char *line, int i)
{
    if (!(is_quote(line[i])) && !(is_blank(line[i])) &&
        !(is_paranthesis(line, i)) && !(is_separator(line, i))
        && is_after_redirect(line, i))
        return (1);
    return (0);
}

int is_after_redirect(char *line, int index)
{
    while (line[index])
    {
        if (is_file_redirection(line , index))
            return (1);
        index--;
    }
    return (0);
}