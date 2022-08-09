/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:56:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/09 16:56:35 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char *heredoc_prompt(char *limiter)
{
    char *line;
    int   fd_tmp;
    char *tmp_file_name;

    tmp_file_name = "tmp.txt";
    fd_tmp = open(tmp_file_name, O_CREAT | O_WRONLY, 0777);
    while (1)
    {
        line = get_next_line(STDIN_FILENO);
        if (same_str(limiter, line, ft_strlen(line)))
            break;
        else
            ft_putstr_fd(line, fd_tmp);
    }
    close(fd_tmp);
    return (tmp_file_name);
}