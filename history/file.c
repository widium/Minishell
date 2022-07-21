/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:24:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/21 21:16:52 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void open_files(t_env    *env)
{
    int fd;
    
    fd = open("history.log", O_CREAT | O_WRONLY, 0777);
    env->history= init_file("history.log", fd);
}