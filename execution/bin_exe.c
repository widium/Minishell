/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 19:22:14 by ebennace         ###   ########.fr       */
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
        printf("---- Execution -----\n");
        execve(path, args, variables);
        perror("Command failure : "); 
    }
    else
    {
        wait(&id);
        return ;
    }
}