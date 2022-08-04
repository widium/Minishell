/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:18:31 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 16:42:54 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void setup_bin_path(t_cmd *cmd, char **bins)
{
    char *command;
    char *path;

    command = cmd->content;
    if (test_absolute_bin_access(command))
    {
        cmd->bin = malloc_strcpy(command);
        return ;
    }
    else if (test_bin_access(bins, command))
    {
        path = create_path_bin(bins, command);
        cmd->bin = path;
        return ;
    }
}

void setup_bin_args(t_cmd *cmd, char **bins)
{
    char *command;

    command = cmd->content;
    if (test_absolute_bin_access(command))
    {
        command = extract_bin_name_in_path(command);
        free(cmd->content);
        cmd->content = command;
        cmd->args = append_bin_name_in_args(cmd->args, cmd->content);
        return ;
    }
    else if (test_bin_access(bins, command))
    {
        cmd->args = append_bin_name_in_args(cmd->args, cmd->content);
        return;
    }
}

char *create_path_bin(char **bins, char *cmd)
{
    int i;
    char *path;

    i = 0;
    while (bins[i])
    {
        path = ft_strjoin_char(bins[i], cmd, '/');
        if (access(path, X_OK & F_OK) == 0)
        {
            return (path);
        }
        free(path);
        i++;
    }
    return (NULL);
}