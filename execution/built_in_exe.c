/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/07 11:54:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void built_in_execution(t_env *env, t_cmd *cmd)
{
    if (is_echo(cmd))
        echo(cmd);
    else if (is_cd(cmd))
        cd(cmd, env);
    else if (is_env(cmd))
        env_built_in(cmd, env);
    else if (is_export(cmd))
        export_built_in(cmd, env);
    else if (is_unset(cmd))
        unset(cmd, env);
    else if (is_pwd(cmd))
        pwd(cmd, env);
}

