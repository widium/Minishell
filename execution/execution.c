/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/04 15:27:25 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void execution(t_env *env)
{
    t_cmd *cmd;
    t_token *token;
    
    if (env->verbose == 1)
        printf("=== Execution ===\n");
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        if (is_cmd_bin(cmd))
        {
            bin_execution(env, cmd);
        }
        else if (is_cmd_built_in(cmd))
        {
            // built_in_execution(cmd);
            printf("c'est un built-in\n");
        }
        token = get_next_token_cmd(token);
    }
    close_all_fd(env);
    wait_all_pid(env);
    if (env->verbose == 1)
        printf("=========\n");
}

void wait_all_pid(t_env *env)
{
    t_token *token;
    t_cmd *cmd;
    
    token = get_first_token(env);
    while (token)
    {
        cmd = get_class(token);
        // fprintf(stderr, "Wait [%s]:[%d]\n", cmd->content, cmd->pid);
        wait(&cmd->pid);
        token = get_next_token_cmd(token);
    }
}