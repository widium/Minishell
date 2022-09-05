/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:21:39 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 14:11:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int check_error_built_in(t_cmd *cmd)
{
    int result;

    result = 0;
    if (is_echo(cmd))
        result += check_error_echo(cmd);
    else if (is_cd(cmd))
        result += check_error_cd(cmd);
    // else if  (is_env(cmd))
    //     result += check_error_echo(cmd);
    // else if  (is_pwd(cmd))
    //     result += check_error_echo(cmd);
    // else if  (is_export(cmd))
    //     result += check_error_echo(cmd);
    // else if  (is_unset(cmd))
    //     result += check_error_echo(cmd);
    // else if  (is_exit(cmd))
    //     result += check_error_echo(cmd);
    return (0);
}

int check_error_echo(t_cmd *cmd)
{
    int nb_arg;
    int result;
    
    result = 0;
    nb_arg = get_number_args(cmd);
    if (nb_arg == 0)
    {
        printf("Error : 0 argument for [echo]\n");
        result += 1;
    }
    return (result);
}

int check_error_cd(t_cmd *cmd)
{
    int nb_arg;
    int result;
    
    result = 0;
    nb_arg = get_number_args(cmd);
    if (nb_arg > 1)
    {
        result++;
        printf("cd : too many arguments.\n");
    }
    return (result);
}