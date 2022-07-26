/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:05:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/26 17:52:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void concatenate_args(t_env *env)
{
    t_token *iter;
    
    iter = env->first_token; 
    while (iter)
    {
        if (is_token_cmd(iter))
        {
            printf("Concatenate : [%s]\n", concatenate((t_cmd *)iter->class));
        }
        iter = iter->next;
    }
}

char *concatenate(t_cmd *cmd)
{
    char *string;
    t_arg *iter;
    t_arg *tmp;

    if (!(cmd->first_arg))
        return (string);
    else
    {
        iter = cmd->first_arg;
        string = iter->content;
        while (iter)
        {
            iter = iter->next;
            string = ft_strjoin(string, iter->content);        
        }
        // remove_arg(cmd, iter);
        return (string);
    }
}
// void remove_arg(t_cmd *cmd, t_arg *arg)
// {
//     t_arg *iter;
//     int i;

//     i = 1;
//     iter = cmd->first_arg;
//     while (iter->next && i < arg->index)
//     {
//         iter = iter->next;
//     }
//     iter->next = NULL;
//     iter->prev = NULL;
//     free(iter->content);
//     free(iter);
// }
