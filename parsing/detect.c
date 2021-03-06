/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/20 17:14:05 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char *return_built_in(char *content)
{
    if (same_str(content, "echo", ft_strlen("echo")))
	    return ("echo");
    if (same_str(content, "cd", ft_strlen("cd")))
	    return ("cd");
    if (same_str(content, "pwd", ft_strlen("pwd")))
	    return ("pwd");
    if (same_str(content, "env", ft_strlen("env")))
	    return ("env");
    if (same_str(content, "export", ft_strlen("export")))
	    return ("export");
    if (same_str(content, "unset", ft_strlen("unset")))
	    return ("unset");
    if (same_str(content, "exit", ft_strlen("exit")))
	    return ("exit");
	return (NULL);
}

int is_built_in(char *content)
{
    if (same_str(content, "echo", ft_strlen("echo")))
	    return (1);
    if (same_str(content, "cd", ft_strlen("cd")))
	    return (1);
    if (same_str(content, "pwd", ft_strlen("pwd")))
	    return (1);
    if (same_str(content, "env", ft_strlen("env")))
	    return (1);
    if (same_str(content, "export", ft_strlen("export")))
	    return (1);
    if (same_str(content, "unset", ft_strlen("unset")))
	    return (1);
    if (same_str(content, "exit", ft_strlen("exit")))
	    return (1);
	return (0);
}

int is_built_in_index(char *line, int index)
{
    if (same_str_index(line, "echo", ft_strlen("echo"), index))
	    return (1);
    else if (same_str_index(line, "cd", ft_strlen("cd"), index))
	    return (1);
    else if (same_str_index(line, "pwd", ft_strlen("pwd"), index))
	    return (1);
    else if (same_str_index(line, "env", ft_strlen("env"), index))
	    return (1);
    else if (same_str_index(line, "export", ft_strlen("export"), index))
	    return (1);
    else if (same_str_index(line, "unset", ft_strlen("unset"), index))
	    return (1);
    else if (same_str_index(line, "exit", ft_strlen("exit"), index))
	    return (1);
    return (0); 
}