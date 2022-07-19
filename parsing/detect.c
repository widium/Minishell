/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:06:27 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/19 18:22:49 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int detect_flags(char *line, int index)
{
    while (line[index] && !(is_blank(line[index])) && !(is_separator(line, index)))
        index++;
    return (index-1);
}

int arguments_detection(char *line, int index)
{
    while (line[index] && !(is_separator(line, index)))
        index++;
    return (index -1);
}

int command_information(t_token *token, char *line, int index)
{
    int start;
    int new_index;
    char *flags;
    char *arg;

    flags = NULL;
    arg = NULL;
    
    start = index;
    new_index = index;
    
    while (line[index])
    {
        if (line[index] == '-')
        {
            new_index = detect_flags(line, index);
            flags = ft_substr(line, index, (new_index - index) + 1);
            index = new_index;
        }
        else if (is_argument(line, index))
        {
            new_index = arguments_detection(line, index);
            arg = ft_substr(line, index, (new_index - index) + 1);
            index = new_index;
        //     printf("FLAGS : %s ARGUMENT : %s\n", flags, arg);
            break;
        }
        index++;
    }
    ((t_cmd *)token->class)->flags = flags;
    ((t_cmd *)token->class)->arg = arg;
    return (index);
	
}

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

// int built_in_detection(char *line, int index)
// {
//     int start;

//     start = index;
//     while (line[i])
//     {
        
//     }
// }