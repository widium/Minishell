/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/18 19:07:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_env	*init_env(char **env_variable)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->verbose = 0;
	env->error_parsing = 0;
	env->error_processing = 0;
	env->variable = init_variable(env_variable);
    env->history = NULL;
	env->first_token = NULL;
	return (env);
}

t_env_var	*init_env_variable(char *name, char *value, int index, int id)
{
	t_env_var	*vars;

	vars = (t_env_var *)malloc(sizeof(t_env_var));
	if (!vars)
		return (NULL);
	vars->index = index;
	vars->id = id;
	vars->name = name;
	vars->value = value;
    vars->next = NULL;
	vars->prev = NULL;
	return (vars);
}

t_variable	*init_variable(char **env_variable)
{
	t_variable	*vars;

	vars = (t_variable *)malloc(sizeof(t_variable));
	if (!vars)
		return (NULL);
	recover_path_and_bins_variable(vars, env_variable);
	vars->variables = env_variable;
	vars->first_var = create_chained_var(vars, env_variable);
	add_signal_env_var(vars);
	t_env_var *var = get_env_var_with_name(vars, "COLORFGBG");
	print_env_var(var);
	remove_env_var(vars, var);
	print_all_env_var(vars);
	return (vars);
}

void remove_env_var(t_variable *variable, t_env_var *var)
{
	t_env_var *iter;

	iter = get_first_env_var(variable);
	if (!iter)
		return ;
	while (iter)
	{
		if (iter->index == var->index)
		{
			disconect_env_var(variable, var);
			free_env_var(var);
			return ;
		}
		iter = iter->next;
	}
}

void add_signal_env_var(t_variable *vars)
{
	t_env_var	*signal_var;
	int 		list_size;
	list_size = get_env_var_size(vars);
	signal_var = init_env_variable("?", "NULL", list_size, NATIF);
	add_new_env_variable(vars, signal_var);
}

char **add_env_variable(char **variables, char *var)
{
	int	last_index;
	char **new_variables;
	
	last_index = ft_strlen_array(variables);
	new_variables = ft_arrayjoin_str(variables, var, last_index);
	return (new_variables);
}

