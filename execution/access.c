/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:35:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 12:01:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void recover_path_variable(t_variable *var, char **env_variable)
{
    char *path;
    char **bins;
    
    path = get_variable_value(env_variable, "PATH");
    bins = get_list_of_bins(path);
    var->variables = env_variable;
    var->path = path;
    var->bins = bins;
}

char **get_list_of_bins(char *path_variable)
{
    char **bins;
    
    bins = ft_split(path_variable, ':');
    return (bins);
}

char **get_bins(t_env *env)
{
    if (env->variable->bins)
        return (env->variable->bins);
    return (NULL);
}

int test_bin_access(char **bins, char *word)
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

int test_absolute_bin_access(char *path)
{
    if (access(path, X_OK & F_OK) == 0)
        return (1);
    return (0);
}