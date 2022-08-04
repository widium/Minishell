/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:03:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 17:49:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_cmd_info(t_cmd *cmd)
{
    printf(" ---[%s]---\n", cmd->content);
    printf(" | type : [%s]\n",convert_id(cmd->id));
    printf(" | path : [%s]\n",cmd->bin);
    printf(" | args : [");
    print_array_index(cmd->args, 1);
    printf("]\n");
    printf(" | fd_in : [%s]\n",convert_fd(cmd->fd_in));
    printf(" | fd_out : [%s]\n",convert_fd(cmd->fd_out));
    printf(" ----------------\n");
}

char *convert_fd(int fd)
{
    if (fd == STDIN_FILENO)
        return ("STDIN");
    else if (fd == STDOUT_FILENO)
        return ("STDOUT");
    else if (fd == STDERR_FILENO)
        return ("STDERR");
    else 
        return (ft_itoa(fd));
}

