/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:05:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 16:56:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void concatenate_args(t_env *env)
{
    t_token *token;
    
    token = env->first_token; 
    while (token)
    {
        if (is_token_cmd(token) && have_args((t_cmd *)token->class))
        {
            ((t_cmd *)token->class)->args = list_to_array(get_class(token));
        }
        token = token->next;
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
        return (complete);
    else
    {
        complete = malloc(sizeof(char *)*size_of_list(cmd) + 1);
        arg = get_first_arg(cmd);
        while (arg)
        {
            complete[i] = malloc_strcpy(arg->content);
            arg = arg->next;
            i++;
        }
        remove_all_arg(cmd);
        complete[i] = NULL;
        
    }
    return (complete);
}

// char *list_to_string(t_cmd *cmd)
// {
//     t_arg *arg;
//     char *complete;
//     int i;
    
//     i = 0;
//     if (!(cmd->first_arg))
//         return (complete);
//     else
//     {
//         complete = malloc(sizeof(char *)*size_of_list(cmd) + 1);
//         arg = get_first_arg(cmd);
//         while (arg)
//         {
//             complete[i] = malloc_strcpy(arg->content);
//             arg = arg->next;
//             i++;
//         }
//         remove_all_arg(cmd);
//         complete[i] = NULL;
        
//     }
//     return (complete);
// }