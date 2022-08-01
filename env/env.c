/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:44:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 13:02:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


void get_variables_value(t_env *env)
{
    t_token *iter;
    t_arg   *arg;
    char    *content;
    
    iter = get_first_token(env);
    while (iter)
    {
        if (is_token_cmd(iter) && token_have_args(iter))
        {
            arg = get_first_arg(get_class(iter));
            while (arg)
            {
                if (is_arg_variable(arg))
                    change_arg_content(env, arg);
                arg = arg->next;
            }
        }
        iter = iter->next;
    }
}

void change_arg_content(t_env *env, t_arg *arg)
{
    char *duplicate;
    
    duplicate = malloc_strcpy(arg->content);
    free(arg->content);
    arg->content = get_variable_value(env->variables, duplicate);
    free(duplicate);
}

char *get_variable_value(char **env, char *variable)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (same_str(env[i], variable, ft_strlen(variable)))
        {
            return (extract_value_variable(env[i], variable));
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