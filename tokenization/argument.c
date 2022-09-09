/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:47:07 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/09 12:33:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


void get_arg_variables_value(t_env *env)
{
    t_token *token;
    t_arg   *arg;
    char    *content;
    
    token = get_first_token(env);
    while (token)
    {
        if (is_token_cmd(token) && token_have_args(token))
        {
            arg = get_first_arg(get_class(token));
            while (arg)
            {
                if (is_arg_variable(arg))
                    change_arg_variable_content(env, arg);
                arg = arg->next;
            }
        }
        token = token->next;
    }
}

void change_arg_variable_content(t_env *env, t_arg *arg)
{
    char *value;
    char **variables;

    variables = env->variable->variables;
    value = malloc_strcpy(arg->content);
    free(arg->content);
    arg->content = get_variable_value(variables, value);
    if (arg->content == NULL)
    {
        printf("Error : unknow variable [%s]\n", value);
        env->error_processing += 1;
    }
    free(value);
}