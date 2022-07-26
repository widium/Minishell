/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:11:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/26 17:34:31 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

t_arg *get_first_arg(t_cmd *cmd)
{
    if (cmd->first_arg)
        return (cmd->first_arg);
    return (0);
}

t_token *get_first_token(t_env *env)
{   
    if (env->first_token)
        return (env->first_token);
    return (0);
}