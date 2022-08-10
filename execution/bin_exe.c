/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/09 18:03:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void bin_execution(t_env *env, t_cmd *cmd)
{
    int id;
    char *path;
    char **args;
    char **variables;

    path = get_cmd_path(cmd);
    args = get_cmd_args(cmd);
    variables = get_env_variables(env);
    id = fork();
    if (id == 0)
    {
        printf("------- Execution --------\n");
        if (cmd_have_standart_fd(cmd))
        {
            execve(path, args, variables);
            perror("Command failure : "); 
        }
        else
        {
            redirect_cmd(cmd);
            close_fd_cmd(cmd);
            execve(path, args, variables);
            perror("Command failure : "); 
        }
    }
    else
    {
        wait(&id);
        return ;
    }
}

void close_fd_cmd(t_cmd *cmd)
{
    if(!(is_standart_fd(cmd->fd_in)))
        close(cmd->fd_in);
    if(!(is_standart_fd(cmd->fd_out)))
        close(cmd->fd_out);
}

int is_standart_fd(int fd)
{
    if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
        return (1);
    return (0);
}

int cmd_have_standart_fd(t_cmd *cmd)
{
    if (is_standart_fd(cmd->fd_in) && is_standart_fd(cmd->fd_out))
        return (1);
    return (0);
}

void redirect_cmd(t_cmd *cmd)
{
    int fd_in;
    int fd_out;

    fd_in = cmd->fd_in;
    fd_out = cmd->fd_out;
    
    if (!(is_standart_fd(cmd->fd_in)))
    {
        dup2(fd_in, STDIN_FILENO);
    }
    if (!(is_standart_fd(cmd->fd_out)))
    {
       dup2(fd_out, STDOUT_FILENO);
    }
}