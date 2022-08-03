/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:03:34 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 17:04:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

// void pipex(t_env *env, t_command *cmd, int *fd, int *fd_next)
// {
//     int id;

//     id = fork();
    
//     // wait(id);
//     if (id == 0)
//     {
//         printf("Child Process {%d}\n", id);
//         // ====== Si c'est la 1er command === //
//         if (cmd->index == 1)
//         {
//             printf("1er command\n");
//         // ====== Redirection Input -> read in_file === //
//             dup2(env->file->fd_in, STDIN_FILENO);
//         }
//         else
//         {
//         // ====== Redirection Input -> 1e pipe reception === //
            
//             //si c'est une command impaire
//             if (cmd->index % 2 != 0)
//                 dup2(fd_next[0], STDIN_FILENO);
//             else
//                 dup2(fd[0], STDIN_FILENO);
//         }
//         if (cmd->index == env->nbr_cmd)
//         {
//             printf("Last command\n");
//         // ====== Redirection Output -> write out_file === //
//             dup2(env->file->fd_out, STDOUT_FILENO);
//         }
//         else 
//         {
//         // ====== Redirection Output -> 1er pipe send === //
        
//         //si c'est une command impaire
//         if (cmd->index % 2 != 0)
//             dup2(fd[1], STDOUT_FILENO);
//         else
//             dup2(fd_next[1], STDOUT_FILENO);
//         }
        
//         close(env->file->fd_in);
//         close(env->file->fd_out);
//         close(fd[0]);
//         close(fd[1]);
//         close(fd_next[0]);
//         close(fd_next[1]);    
//         exec_command(cmd);
//         perror("In command failure : "); 
//         }
// }