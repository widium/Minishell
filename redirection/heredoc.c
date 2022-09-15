/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:56:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/15 17:12:58 by ebennace         ###   ########.fr       */
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
        ft_putstr_fd("> ", 1);
        line = get_next_line(STDIN_FILENO);
        if (same_str(limiter, line, (ft_strlen(line) - 1)))
            break;
        else
            ft_putstr_fd(line, fd_tmp);
    }
    close_fd(tmp_file_name, fd_tmp);
    return (tmp_file_name);
}

char *heredoc_not_finish(char *limiter)
{
    char *line;
    int   fd_tmp;
    char *content;

    fd_tmp = open("tmp.txt", O_CREAT | O_WRONLY, 0777);
    while (1)
    {
        ft_putstr_fd("> ", 1);
        line = get_next_line(STDIN_FILENO);
        if (same_str(limiter, line, ft_strlen(limiter)))
        {
            free(line);
            break;
        }
        else
            ft_putstr_fd(line, fd_tmp);
        free(line);
    }
    close(fd_tmp);
    content = read_and_extract_content_file("tmp.txt");
    unlink("tmp.txt");
    return (content);
}

char *read_and_extract_content_file(char *path)
{
    int fd;
    char *buf;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buf = ft_calloc(BUFF_SIZE, sizeof(char));
    if (read(fd, buf, BUFF_SIZE) != -1)
        return (buf);
    else 
        free(buf);
    return (NULL); 
        
}