/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/13 17:47:34 by ebennace         ###   ########.fr       */
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

int is_boolean_operator(char *str, int i)
{
    if (is_doublons(str, i, '&') || is_doublons(str, i, '|'))
        return (1);
    return (0);
}

int is_separator(char *line, int i)
{
    if (is_redirection(line, i) || is_boolean_operator(line, i))
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

int is_double_quote(char c)
{
    if (c == '\"')
        return (1);
    return (0);
}

int is_single_quote(char c)
{
    if (c == '\'')
        return (1);
    return (0);
}

int is_word(char *line, int i)
{
    if (!(is_single_quote(line[i])) && !(is_double_quote(line[i])) && !(is_blank(line[i])) &&
     !(is_paranthesis(line, i)) && !(is_redirection(line, i)))
        return (1);
    return (0);
}

int is_variable(char *line, int index)
{
    if (line[index] == '$' && !(is_blank(line[index + 1])))
        return (1);
    return (0);
}

int is_paranthesis(char *line, int index)
{
    if ((line[index] == '(' || line[index] == ')') && line[index - 1] != '\\')
        return (1);
    return (0);
}

int is_in_double_quote(char *line, int index)
{
    int first;
    int last;
    int backup;

    first = 0;
    last = 0;
    backup = index;
    while (line[index])
    {
        if (is_double_quote(line[index]))
        {
            first++;
            break;
        }
        index--;
    }
    index = backup;
    while (line[index])
    {
        if (is_double_quote(line[index]))
        {
            last++;
            break;
        }  
        index++;
    }
    if (first && last)
        return (1);
    return (0);
    
}

int is_in_single_quote(char *line, int index)
{
    int first;
    int last;
    int backup;

    first = 0;
    last = 0;
    backup = index;
    while (line[index])
    {
        if (is_single_quote(line[index]))
        {
            first++;
            break;
        }
        index--;
    }
    index = backup;
    while (line[index])
    {
        if (is_single_quote(line[index]))
        {
            last++;
            break;
        }  
        index++;
    }
    if (first && last)
        return (1);
    return (0);
    
}

int is_in_quote(char *line, int index)
{
    if (is_in_double_quote(line, index) || is_in_single_quote(line, index))
        return (1);
    return (0);
}