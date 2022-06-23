/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:07:02 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/23 13:09:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void use_signal(t_env *env, int key)
{
    if (key == 0)
    {
        // free_all(env);
        signal(SIGQUIT, exit_prompt);
    }
        
}

void exit_prompt(int key)
{
    printf("Exit...\n");
    exit(0);
    
}