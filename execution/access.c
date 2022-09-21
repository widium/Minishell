/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:35:35 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/19 15:02:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void recover_path_and_bins_variable(t_variable *var, char **env_variable)
{
    char *path;
    char **bins;
    
    var->path = get_variable_value(env_variable, "PATH");
    var->bins = get_list_of_bins(var, path);
}

char **get_list_of_bins(t_variable *vars, char *value)
{
    char **bins;

    bins = ft_split(value, ':');
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