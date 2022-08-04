/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:02:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 17:40:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

char **append_bin_name_in_args(char **args, char *name)
{
    char **new_args;
    
    new_args = ft_arrayjoin_str(args, name, 0);
    free(args);
    return (new_args);
}

char *extract_bin_name_in_path(char *path)
{
    int index;
    char *name;
    
    index = ft_strlen(path);
    while (index > 0)
    {
        if (path[index] == '/')
            break;
        index--;
    }
    name = malloc_strcpy_after_index(path, index + 1);
    return (name);
}