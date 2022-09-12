/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:03:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/12 15:10:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_cmd_info(t_cmd *cmd)
{
    printf(" ---[%s]---\n", cmd->content);
    printf(" | type : [%s]\n",convert_id(cmd->id));
    if (is_cmd_bin(cmd))
    {
        printf(" | path : [%s]\n", cmd->bin);
        printf(" | args : [");
        print_array(cmd->args);
        printf("]\n"); 
    }
    else if (is_cmd_built_in(cmd))
    {
        printf(" | arg : [%s]\n", cmd->arg);
        printf(" | flags : [%s]\n", cmd->flags);
    }
    printf(" | fd_in : [%s]\n",convert_fd(cmd->fd_in));
    printf(" | fd_out : [%s]\n",convert_fd(cmd->fd_out));
    if (cmd_have_args(cmd))
        print_args(cmd);
    printf(" ----------------\n");
}

void print_all_cmd_info(t_env *env)
{
    t_token *token;
    t_cmd *cmd;

    token = get_first_token_cmd(env);
    while (token)
    {
        if (is_token_cmd(token))
        {
            cmd = get_class(token);
            print_cmd_info(cmd);
        }
        token = get_next_token_cmd(token);
    }
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

