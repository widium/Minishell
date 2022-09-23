/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:24:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 18:40:35 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void open_history_file(t_env    *env)
{
    int fd;
    
    fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0777);
    env->history = init_file("history.log", fd);
}