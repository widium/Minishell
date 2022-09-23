/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:05:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 17:13:36 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void concatenate_cmd_args(t_env *env)
{
    t_token *token;
    t_cmd *cmd;
    
    token = env->first_token; 
    while (token)
    {
        if (is_token_cmd(token))
        {
            cmd = get_class(token);
            if (cmd_have_args(cmd))
            {
                if (is_cmd_bin(cmd))
                {
                    remove_blank_arg(cmd);
                    cmd->args = list_to_array(cmd);
                }
                else if (is_cmd_built_in(cmd))
                    cmd->arg = list_to_string(cmd);
            }
        }
        token = token->next;
    }
}

void remove_blank_arg(t_cmd *cmd)
{
    t_arg *arg;
    t_arg *iter;

    iter = get_first_arg(cmd);
    arg = iter;
    while (iter)
    {
        iter = arg->next;
        if (is_arg_blank(arg))
        {
            if (arg->index == 1)
                cmd->first_arg = NULL;
            remove_arg(arg);
        }
        arg = iter;
    }
}

int size_of_list(t_cmd *cmd)
{
    t_arg *arg;
    int i;

    arg = get_first_arg(cmd);
    i = 0;
    while (arg)
    {
        i++;
        arg = arg->next;
    }
    return (i);
}

char **list_to_array(t_cmd *cmd)
{
    t_arg *arg;
    char **complete;
    int i;
    
    i = 0;
    if (!(cmd->first_arg))
        return (NULL);
    arg = get_first_arg(cmd);
    if (arg->content == NULL)
        return (NULL);
    complete = malloc(sizeof(char *)*(size_of_list(cmd) + 1));
    while (arg)
    {
        complete[i] = malloc_strcpy(arg->content);
        arg = arg->next;
        i++;
    }
    remove_all_arg(cmd);
    complete[i] = NULL;
    return (complete);
}

char *list_to_string(t_cmd *cmd)
{
    t_arg *arg;
    char *complete;
    
    if (!(cmd_have_args(cmd)))
        return (NULL);
    arg = get_first_arg(cmd);
    if (arg->content == NULL)
        return (NULL);
    complete = malloc_strcpy(arg->content);
    arg = arg->next;
    while (arg)
    {
        complete = ft_strjoin_free_first(complete, arg->content);
        arg = arg->next;
    }
    remove_all_arg(cmd);
    return (complete);
}