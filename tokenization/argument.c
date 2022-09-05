/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:47:07 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/04 18:16:31 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


void get_arg_variables_value(t_env *env)
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
                    change_arg_variable_content(env, arg);
                arg = arg->next;
            }
        }
        iter = iter->next;
    }
}

void change_arg_variable_content(t_env *env, t_arg *arg)
{
    char *duplicate;
    char **variables;

    variables = env->variable->variables;
    duplicate = malloc_strcpy(arg->content);
    free(arg->content);
    arg->content = get_variable_value(variables, duplicate);
    free(duplicate);
}