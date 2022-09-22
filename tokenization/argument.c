/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:47:07 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 09:48:10 by ebennace         ###   ########.fr       */
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

int variable_exist(t_env *env, char *name)
{
    t_variable *vars;
    t_env_var *var;

    vars = env->variable;
    var = get_env_var_with_name(vars, name);
    if (!var)
        return (0);
    if (same_name(var->name, name))
        return (1);
    return (0);    
}

void change_arg_variable_content(t_env *env, t_arg *arg)
{
    char *name;
    char *value;
    t_variable *variable;
    t_env_var *var;
    

    variable = env->variable;
    name = malloc_strcpy(arg->content);
    free(arg->content);
    value = get_env_var_value_with_name(variable, name);
    if (value == NULL)
    {
        printf("Error : unknow variable [%s]\n", name);
        env->error_processing += 1;
    }
    else
        arg->content = malloc_strcpy(value);
    free(name);
}