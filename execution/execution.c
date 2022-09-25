/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 17:07:26 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void execution(t_env *env)
{
    t_cmd *cmd;
    t_token *token;
    int status_built_in;
    int status;
    char **variables;
    
    if (env->verbose == 1)
        printf("=== Execution ===\n");
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        if (is_cmd_bin(cmd))
        {
            variables = get_env_variables(env);
            bin_execution(env, cmd, variables);
            free_array(variables);
        }
        else if (is_cmd_built_in(cmd) && cmd_have_argument(cmd))
        {
            status_built_in = built_in_execution(env, cmd);
        }
        token = get_next_token_cmd(token);
    }
    close_all_fd(env);
    status = wait_all_pid(env);
    status = get_last_status(status, status_built_in);
    update_variable_status_process(env, status);
    if (env->verbose == 1)
        printf("=========\n");
}

int get_last_status(int bin_status, int ret_built_in)
{
    if (bin_status == -1)
        return (ret_built_in);
    else if (ret_built_in == -1)
        return (bin_status);
}

int wait_all_pid(t_env *env)
{
    t_token *token;
    t_cmd *cmd;
    int status;
    
    status = -1;
    token = get_first_token_cmd(env);
    while (token)
    {
        cmd = get_class(token);
        waitpid(cmd->pid, &status, 0);
        status = convert_status_process_value(status);
        token = get_next_token_cmd(token);
    }
    return (status);
}

int convert_status_process_value(int status)
{
    if(WIFSIGNALED(status))
        status = WEXITSTATUS(status);
    if (WIFEXITED(status))
        status = WEXITSTATUS(status);
    return (status);
}

void update_variable_status_process(t_env *env, int status)
{
    t_env_var *var;
    char *value;
    
    value = ft_itoa(status);
    if (!value)
        return ;
    var = get_env_var_with_name(env, "?");
    if (!var)
    {
        free(value);
        return ;
    }
    if (var->value)
        free(var->value);
    var->value = value;
    var->id = VALUE;
}