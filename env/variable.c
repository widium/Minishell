/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 11:09:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


char *get_env_variable_value(char *variable)
{
    int i;
    int start;
    int end;
    char *value;
    
    i = 0;
    if (!variable)
        return (NULL);
    while (variable[i])
    {
        if (variable[i] == '=')
        {
            start = i + 1;
            end = ft_strlen(variable);
            value = malloc_substrcpy(variable, start, (end - start) + 1);
            return (value);
        }
        i++;
    }
    return (NULL);
}

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

int same_name(char *first, char *second)
{
    if (same_str(first, second, ft_strlen(second)))
    {
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
    if (!variable)
        return (NULL);
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
    end = index;
    name = malloc_substrcpy(variable, start, (end - start) + 1);
    return (name);
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

char *extract_value_variable(char *env_variable, char *variable)
{
    int start;
    int end;
    char *content;

    start = 0;
    end = 0;

    start = index_diff(env_variable, variable, ft_strlen(variable)) + 1;
    end = ft_strlen(env_variable);
    content = malloc_substrcpy(env_variable, start, (end - start) + 1);
    return (content);
}