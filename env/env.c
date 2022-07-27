/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:44:46 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 14:21:55 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


void change_variable_token(t_env *env)
{
    t_token *iter;
    t_arg   *arg;
    char    *content;
    
    iter = get_first_token(env);
    while (iter)
    {
        if (is_token_cmd(iter))
        {
            if (token_have_args(iter))
            {
                arg = get_first_arg((t_cmd *)iter->class);
                while (arg)
                {
                    if (is_arg_variable(arg))
                    {
                        content = arg->content;
                        arg->content = get_variable(env->variables, content);
                        free(content);
                    }
                    arg = arg->next;
                }
            }
        }
        iter = iter->next;
    }
}
char *get_variable(char **env, char *variable)
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