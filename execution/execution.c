/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/21 18:33:29 by ebennace         ###   ########.fr       */
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
        else if (is_cmd_built_in(cmd) && cmd_have_argument(cmd))
        {
            built_in_execution(env, cmd);
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
    int status;
    
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        waitpid(cmd->pid, &status, 0);
        update_variable_status_process(env, status);
        token = get_next_token_cmd(token);
    }
}

void update_variable_status_process(t_env *env, int status)
{
    char *value;
    char *value_var;

    value = ft_itoa(status);
    if (!value)
        return ;
    value_var = malloc_strcpy(value);
    free(value);
    change_env_var_value_with_name(env, "?", value_var);
}