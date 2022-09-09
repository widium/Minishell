/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:07:02 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/09 12:50:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void use_signal(void)
{
    signal(SIGQUIT, pass);
    signal(SIGINT, call_prompt);
        
}

void call_prompt(int key)
{
    write(1, "\n", 1);
    rl_replace_line("", 0);
    rl_on_new_line();
    rl_redisplay();
}

void pass(int key)
{
    printf("CTRL + \\");
    return;
}

void exit_prompt(int key)
{
    printf("Exit...\n");
    exit(0);
    
}