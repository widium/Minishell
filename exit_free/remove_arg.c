/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:40:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/27 17:06:53 by ebennace         ###   ########.fr       */
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
        free_arg(arg);
        arg = iter;
    }
}

void disconect_arg(t_arg *arg)
{
    arg->next = NULL;
    arg->prev = NULL; 
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
    free_arg(iter);
}

void free_arg(t_arg *arg)
{
    disconect_arg(arg);
    free(arg->content);
    free(arg);
}

void my_free(void **ptr)
{
    if (!*ptr)
        free(*ptr);
    *ptr = NULL;
}