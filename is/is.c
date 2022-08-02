/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:59:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_finish(char c)
{
    if (c == '\0')
        return (1);
    return (0);
}
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

int is_separator(char *line, int i)
{
    if (is_redirection(line, i) || is_boolean_operator(line, i))
        return (1);
    return (0);    
}

int is_delimiter(char *line, int index)
{
    if (is_blank(line[index]) || is_paranthesis(line, index) ||
     is_separator(line, index) || is_variable(line, index))
        return (1);
    return (0);    
}

int is_not_NULL(char c, char d)
{
	if (c && d)
		return (1);
	return (0);
}

int is_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int is_back_slash(char c)
{
    if (c == '\\')
        return (1);
    return (0);
}

int is_word(char *line, int i)
{
    if (!(is_quote(line[i])) && !(is_blank(line[i])) &&
     !(is_paranthesis(line, i)) && !(is_separator(line, i)) &&
     !(is_variable(line, i)))
        return (1);
    return (0);
}

int is_argument(char *line, int i)
{
    if (!(is_paranthesis(line, i)) && !(is_separator(line, i)) &&
    !(is_blank(line[i])))
        return (1);
    return (0);
}

int is_paranthesis(char *line, int index)
{
    if ((line[index] == '(' || line[index] == ')') && line[index - 1] != '\\')
        return (1);
    return (0);
}

int is_variable(char *line, int i)
{
    if (line[i] == '$' && !(is_blank(line[i + 1])) && !(is_finish(line[i + 1])))
        return (1);
    return (0);
}

int is_bin(t_env *env, char *word)
{
    char *path;

    path = ft_strjoin("/bin/", word);
    if (access(path, X_OK & F_OK) == 0)
    {
        free(path);
        return (1); 
    }
    free(path);
    return (0);
}

int is_cmd(t_env *env, char *word)
{
    if (is_bin(env, word) || is_built_in(word))
        return (1);
    return (0);
}

int is_flags(char *line, int i)
{
    if (line[i] == '-' && !(is_blank(line[i+1])))
        return (1);
    return (0);
}