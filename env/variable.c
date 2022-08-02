/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:45:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:46:35 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char *get_variable_value(char **variables, char *variable)
{
    int i;

    i = 0;
    while (variables[i])
    {
        if (same_str(variables[i], variable, ft_strlen(variable)))
        {
            return (extract_value_variable(variables[i], variable));
        }
        i++;
    }
    return (0);
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
    content = ft_substr(env, start, (end - start) + 1);
    return (content);
}