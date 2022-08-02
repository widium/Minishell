/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 17:36:55 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void execution(t_env *env)
{
    t_cmd *cmd;

    cmd = get_first_cmd(env);
    if (is_cmd_bin(cmd))
    {
       printf("c'est un bin\n");
    }
    else if (is_cmd_built_in(cmd))
    {
        printf("c'est un built-in\n");
    }
}

void bin_execution(t_env *env, t_cmd *cmd)
{
    
}

void built_in_execution(t_env *env, t_cmd *cmd)
{
    
}