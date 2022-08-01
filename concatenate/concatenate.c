/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:05:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 16:00:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void concatenate_args(t_env *env)
{
    t_token *iter;
    
    iter = env->first_token; 
    while (iter)
    {
        if (is_token_cmd(iter) && have_args((t_cmd *)iter->class))
        {
            ((t_cmd *)iter->class)->args = concatenate((t_cmd *)iter->class);
        }
        iter = iter->next;
    }
}

char **concatenate(t_cmd *cmd)
{
    char *first;
    char *concat;
    char **complete;
    t_arg *arg;
    t_arg *tmp;

    if (!(cmd->first_arg))
        return (complete);
    else
    {
        arg = get_first_arg(cmd);
        first = malloc_strcpy(arg->content);
        concat = first;
        while (arg->next)
        {    
            tmp = arg->next;
            remove_arg(arg);
            arg = tmp;
            
            printf("CONCAT [%s] + [%s]\n", concat, arg->content);
            concat = ft_strjoin_space(concat, arg->content);    
        }
        free(first);
        printf("CONCAT : %s\n", concat);
        complete = ft_split(concat, ' ');
    }
    return (complete);
}