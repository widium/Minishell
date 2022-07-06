/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/06 13:10:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_single(char *str, int i, int c)
{
    if (str[i - 1] == ' ' && str[i] == c && str[i + 1] == ' ')
        return (1);
    return (0);
}

int is_doublons(char *str, int i, int c)
{
    if (str[i - 1] == ' ' && str[i] == c && str[i + 1] == c && str[i + 2] == ' ')
        return (1);
    return (0);
}

int is_boolean_operator(char *str, int i)
{
    if (is_doublons(str, i, '&') || is_doublons(str, i, '|'))
        return (1);
    return (0);
}

int is_redirection(char *str, int i)
{
    if (is_single(str, i, '|') || is_single(str, i, '>') ||
            is_single(str, i, '<') || is_doublons(str, i, '>>'))
        return (1);
    return (0);
}