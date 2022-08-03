/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:18:31 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 12:19:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void setup_bin_path(t_cmd *cmd, char **bins)
{
    char *command;
    char *path;
    int i;

    command = cmd->content;
    if (test_absolute_bin_access(command))
    {
        path = command;
        cmd->bin = path;
        return ;
    }
    else if (test_bin_access(bins, command))
    {
        path = create_path_bin(bins, command);
        cmd->bin = path;
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