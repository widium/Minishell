/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/09 17:04:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char *get_variable_value(char **variables, char *variable)
{
    int i;

    i = 0;
    while (variables[i])
    {
        if (same_name(variables[i], variable))
        {
            return (extract_value_variable(variables[i], variable));
        }
        i++;
    }
    return (NULL);
}

int same_name(char *variable, char *var)
{
    char *var_name;

    var_name = get_variable_name(variable);
    if (same_str(var_name, var, ft_strlen(var_name)))
    {
        free(var_name);
        return (1); 
    }
        
    return (0);
}

char *get_variable_name(char *variable)
{
    int index;
    int start;
    int end;
    char *name;

    index = 0;
    start = 0;
    while (variable[index])
    {
        if (variable[index] == '=')
        {
            end = index - 1;
            name = malloc_substrcpy(variable, start, (end - start) + 1);
            return (name);
        }
        index++;
    }
    return (NULL);
    
}

int get_variable_index(char **variables, char *variable)
{
    int i;

    i = 0;
    while (variables[i])
    {
        if (same_str(variables[i], variable, ft_strlen(variable)))
            return (i);
        i++;
    }
    return (-1);
}

char *extract_value_variable(char *env, char *variable)
{
    int start;
    int end;
    char *content;

    start = 0;
    end = 0;

    start = index_diff(env, variable, ft_strlen(variable)) + 1;
    end = ft_strlen(env);
    content = malloc_substrcpy(env, start, (end - start) + 1);
    return (content);
}