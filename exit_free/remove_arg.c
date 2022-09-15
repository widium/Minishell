/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:40:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/15 14:16:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all_arg(t_cmd *cmd)
{
    t_arg *arg;
    t_arg *iter;

    if (!(cmd->first_arg))
        return;
    arg = cmd->first_arg;
    while (arg)
    {
        iter = arg->next;
        remove_arg(arg);
        arg = iter;
    }
    cmd->first_arg = NULL;
}

void disconect_arg(t_arg *current_arg)
{
    t_arg *arg_prev;
    t_arg *arg_next;

    arg_prev = current_arg->prev;
    arg_next = current_arg->next;
    
    if (arg_prev)
      arg_prev->next = arg_next;
    if (arg_next)
      arg_next->prev = arg_prev;
    current_arg->next = NULL;
    current_arg->prev = NULL; 
}

void remove_arg_index(t_cmd *cmd, t_arg *arg)
{
    t_arg *iter;
    int i;

    i = 1;
    iter = cmd->first_arg;
    while (iter->next && i < arg->index)
    {
        iter = iter->next;
    }
    remove_arg(iter);
}

void remove_arg(t_arg *arg)
{
    disconect_arg(arg);
    if (arg->content)
    {
        free(arg->content);
        arg->content = NULL;
    }
    if (arg)
    {
        free(arg);
        arg = NULL;
    }
}

void remove_arg_in_cmd(t_cmd *cmd, t_arg *arg)
{
    remove_arg(arg);
    if (get_number_args(cmd) <= 1)
        cmd->first_arg = NULL;
    
}

void my_free(void **ptr)
{
    if (!*ptr)
        free(*ptr);
    *ptr = NULL;
}