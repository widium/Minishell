/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 15:10:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void bin_execution(t_env *env, t_cmd *cmd)
{
    int pid;
    char *path;
    char **args;
    char **variables;

    path = get_cmd_path(cmd);
    args = get_cmd_args(cmd);
    variables = get_env_variables(env);
    pid = fork();
    if (pid == 0)
    {
        if (cmd_have_standart_fd(cmd))
        {
            execve(path, args, variables);
            perror("Command failure : "); 
        }
        else
        {
            redirect_cmd(cmd);
            close_all_fd(env);
            execve(path, args, variables);
            perror("Command failure : ");
        }
    }
    else
    {
        cmd->pid = pid;
        return ;
    }
}

void redirect_cmd(t_cmd *cmd)
{
    int fd_in;
    int fd_out;

    fd_in = cmd->fd_in;
    fd_out = cmd->fd_out;
    
    if (is_not_standard_fd(fd_in))
    {
        dup2(fd_in, STDIN_FILENO);
        // fprintf(stderr, "DUP [%s] : fd_in [%d], STDIN_FILENO [%d]\n", cmd->content, fd_in, STDIN_FILENO);
    }
    if (is_not_standard_fd(fd_out))
    {
        dup2(fd_out, STDOUT_FILENO);
        // fprintf(stderr, "DUP [%s]: fd_out [%d], STDOUT_FILENO [%d]\n",cmd->content, fd_out, STDOUT_FILENO);
    }
}