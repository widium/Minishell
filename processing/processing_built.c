/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_built.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:47:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 17:18:18 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void processing_built_in(t_env *env)
{
    t_token *token;
    t_cmd *cmd;

    token = get_first_token_built_in(env);
    while (token)
    {
        cmd = get_class(token);
        choose_processing_built_in(env, cmd);
        token = get_next_token_built_in(token);
    }
}

void choose_processing_built_in(t_env *env, t_cmd *cmd)
{
    if (is_cd(cmd))
        processing_cd(env, cmd);
    else if (is_echo(cmd))
        processing_echo(cmd);
}

void processing_echo(t_cmd *cmd)
{
    t_arg *arg;

    if (cmd_have_arg_flags(cmd))
    {
        arg = get_cmd_flags(cmd);
        cmd->flags = malloc_strcpy(arg->content);
        remove_arg_in_cmd(cmd, arg);
    }
}
void processing_cd(t_env *env, t_cmd *cmd)
{
    t_arg *arg;

    if (!(cmd_have_args(cmd)))
        cmd->arg = get_home_path(env);
}

int return_last_back_slash_index(char *str)
{
    int i;

    i = ft_strlen(str);
    while (i > 0)
    {
        if (str[i] == '/')
            return (i);
        i--;
    }
    return (ft_strlen(str));
}
// void processing_current_path(t_env *env, t_cmd *cmd)
// {
    
// }

// void processing_home_path(t_env *env, t_cmd *cmd)
// {
    
// }