/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:36:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/05 14:38:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void built_in_execution(t_env *env, t_cmd *cmd)
{
    printf("c'est un built-in\n");
    // choose_built_in(env, cmd);
}

// void choose_built_in(t_env *env, t_cmd *cmd)
// {
//     char *content;
    
//     content = cmd->content;
//     if (same_str(content, "echo", ft_strlen("echo")))
// 	    echo(cmd->args);
//     else if (same_str(content, "cd", ft_strlen("cd")))
//         cd();
//     else if (same_str(content, "pwd", ft_strlen("pwd")))
//         echo();   
//     else if (same_str(content, "env", ft_strlen("env")))
//         env_built_in();
//     else if (same_str(content, "export", ft_strlen("export")))
//         export_built_in();
//     else if (same_str(content, "unset", ft_strlen("unset")))
//         unset();
//     else if (same_str(content, "exit", ft_strlen("exit")))
//         exit();
// 	return (NULL);
// }


