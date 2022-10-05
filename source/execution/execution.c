/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:10 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_env *env)
{
	t_token	*token;
	int		status;
	int		status_built;

	if (env->verbose == 1)
		ft_printf("=== Execution ===\n");
	token = get_first_token_cmd(env);
	while (token)
	{
		status_built = execute_cmd(env, token);
		token = get_next_token_cmd(token);
	}
	close_all_fd(env);
	status = wait_all_pid(env);
	status = get_last_status(status, status_built);
	update_variable_status_process(env, status);
	if (env->verbose == 1)
		ft_printf("=========\n");
}

int	execute_cmd(t_env *env, t_token *token)
{
	t_cmd	*cmd;
	char	**variables;
	int		status_built;

	status_built = -1;
	cmd = get_class(token);
	if (is_cmd_bin(cmd))
	{
		variables = get_env_variables(env);
		bin_execution(env, cmd, variables);
	}
	else if (is_cmd_built_in(cmd))
	{
		status_built = built_in_execution(env, cmd);
	}
	return (status_built);
}

int	wait_all_pid(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;
	int		status;

	token = get_first_token_bin(env);
	status = 0;
	while (token)
	{
		cmd = get_class(token);
		waitpid(cmd->pid, &status, 0);
		status = convert_status_process_value(status);
		token = get_next_token_bin(token);
	}
	return (status);
}
