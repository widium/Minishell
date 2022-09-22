/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:00:19 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 09:10:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void create_chained_var(t_variable *variable, char **env_variable)
{	
	int index;
	char *name;
	char *value;
	t_env_var *var;
	
	index = 0;
	while (env_variable[index])
	{
		name = get_variable_name(env_variable[index]);
		value = get_env_variable_value(env_variable[index]);
		var = init_env_variable(name, value, VALUE);
		add_variables_list(variable, var);
		index++;
	}
}

void add_new_env_variable(t_variable *variable, t_env_var *new)
{
    t_env_var *last_var;

    last_var = get_last_env_var(variable);
    if (!last_var)
        return ;
    connect_new_var(last_var, new, NULL);
    new->index = last_var->index + 1;
}

void connect_new_var(t_env_var *prev_var, t_env_var *curr_var, t_env_var *next_var)
{
    if (!prev_var)
        curr_var->prev = NULL;
    else
    {
        curr_var->prev = prev_var;
        prev_var->next = curr_var;
    }
    if (!next_var)
        curr_var->next = NULL;
    else
    {
        curr_var->next = next_var;
        next_var->prev = curr_var;
    }
}