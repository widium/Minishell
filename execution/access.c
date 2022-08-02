/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:35:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:57:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void recover_path_variable(t_variable *var, char **env_variable)
{
    char *path;
    char **bins;
    
    path = get_variable_value(env_variable, "PATH");
    bins = ft_split(path, ':');
    var->variables = env_variable;
    var->path = path;
    var->list_of_bin = bins;
}

int test_access(char **bins, char *word)
{
    int i;
    char *path;

    i = 0;
    while (bins[i])
    {
        path = ft_strjoin_char(bins[i], word, '/');
        if (access(path, X_OK & F_OK) == 0)
        {
            free(path);
            return (1);
        }
        free(path);
        i++;
    }
    return (0);
}