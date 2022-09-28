/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/26 13:57:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_env *env)
{
	t_token	*token;
	int		status;
	int		status_built_in;

	if (env->verbose == 1)
		printf("=== Execution ===\n");
	token = get_first_token_cmd(env);
	while (token)
	{
		status_built_in = execute_cmd(env, token);
		token = get_next_token_cmd(token);
	}
	close_all_fd(env);
	status = wait_all_pid(env);
	status = get_last_status(status, status_built_in);
	update_variable_status_process(env, status);
	if (env->verbose == 1)
		printf("=========\n");
}

int	execute_cmd(t_env *env, t_token *token)
{
	t_cmd	*cmd;
	char	**variables;
	int		status_built_in;

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
		return (status_built_in);
	}
}

int	wait_all_pid(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;
	int		status;

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
