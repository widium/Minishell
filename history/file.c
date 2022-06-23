/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:24:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/22 11:57:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void open_files(t_env    *env)
{
    env->history->name = "history.log";
    env->history->fd = open(env->history->name, O_CREAT | O_WRONLY, 0777);
    if (env->history->fd == -1)
        return ;
}