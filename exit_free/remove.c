/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:20:16 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/11 15:40:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all(t_env *env)
{
    remove_all_token(env);
    remove_variable(env->variable);
    free(env->history);
    free(env);
}

void remove_variable(t_variable *var)
{
    free(var->path);
    free_array(var->bins);
    free_array(var->variables);
    free(var);
    
}

// void exit_shell(t_env *env)
// {
    
// }