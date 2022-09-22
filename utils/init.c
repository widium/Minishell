/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:49:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 09:10:59 by ebennace         ###   ########.fr       */
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

t_env_var	*init_env_variable(char *name, char *value, int id)
{
	t_env_var	*var;

	var = (t_env_var *)malloc(sizeof(t_env_var));
	if (!var)
		return (NULL);
	var->index = -1;
	var->id = id;
	var->name = name;
	var->value = value;
    var->next = NULL;
	var->prev = NULL;
	return (var);
}

t_variable	*init_variable(char **env_variable)
{
	t_variable	*vars;

	vars = (t_variable *)malloc(sizeof(t_variable));
	if (!vars)
		return (NULL);
	vars->first_var = NULL;
	create_chained_var(vars, env_variable);
	vars->path = get_env_var_value_with_name(vars, "PATH");
    vars->bins = get_list_of_bins(vars, vars->path);
	vars->variables = env_variable;
	add_signal_env_var(vars);
	return (vars);
}

void remove_and_disconect_env_var(t_variable *variable, t_env_var *var)
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
	char		*value;
	char		*name;

	name = malloc_strcpy("?");
	value = malloc_strcpy("NULL");
	signal_var = init_env_variable(name, value, VALUE);
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

