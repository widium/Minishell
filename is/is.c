/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:53:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/13 13:55:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

int is_finish(char c)
{
    if (c == '\0')
        return (1);
    return (0);
}

int is_not_finish(char c)
{
    if (c != '\0')
        return (1);
    return (0);
}

int line_is_finish(char *line, int index)
{
    if (is_finish(line[index]) || index >= ft_strlen(line))
        return (1);
    return (0);
}

int line_is_not_finish(char *line, int index)
{
    if (is_not_finish(line[index]) && index < ft_strlen(line))
        return (1);
    return (0);
}

int	line_is_empty(char	*line)
{
	if (ft_strlen(line) == 0)
		return (1);
	else 
		return (0);
}

int	line_is_not_empty(char	*line)
{
	if (line != NULL && ft_strlen(line) > 0)
		return (1);
	else 
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
    if (is_redirection(line, i) || is_boolean_operator(line, i)
        || is_blank_before_finish(line, i))
        return (1);
    return (0);    
}

int is_delimiter(t_env *env, char *line, int index)
{
    if (is_blank(line[index]) || is_paranthesis(line, index) ||
     is_separator(line, index) || is_variable(env, line, index))
        return (1);
    return (0);    
}

int is_argument_separator(t_env *env, char *line, int index)
{
    if (is_paranthesis(line, index) || is_separator(line, index) ||
     is_variable(env, line, index))
        return (1);
    return (0);
}

int is_blank_before_redirection(char *line, int index)
{
    if (is_blank(line[index]) && is_separator(line, index + 1))
        return (1);
    return (0);
}

int is_blank_before_finish(char *line, int index)
{
    if (is_blank(line[index]))
    {
        while (line[index] && is_blank(line[index]))
        {
            if (is_finish(line[index + 1]))
            {
               return (1); 
            }   
            index++;
        }    
        
    }
    return (0);
}

int is_not_NULL(char c, char d)
{
	if (c && d)
		return (1);
	return (0);
}

int is_NULL(char *line)
{
    if (line == NULL)
        return (1);
    return (0);
}

int is_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return (1);
    return (0);
}

int is_blank_argument(t_env *env, char *line, int index)
{
    if (is_blank(line[index]) && !(is_blank(line[index + 1])) 
        && !(is_separator(line, index + 1)) && is_word(env, line, index + 1) 
        && !(is_finish(line[index + 1])))
        return (1);
    return (0);
}

int is_back_slash(char c)
{
    if (c == '\\')
        return (1);
    return (0);
}

int is_word(t_env *env, char *line, int i)
{
    if (!(is_quote(line[i])) && !(is_blank(line[i])) &&
     !(is_paranthesis(line, i)) && !(is_separator(line, i)) &&
     !(is_variable(env, line, i)))
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

int is_variable(t_env *env, char *line, int i)
{
    char *name;
    if (is_variable_word(line, i))
    {
        name = variable_detection(env, line, ++i);
        if (variable_exist(env, name))
        {
            free(name);
            return (1);
        }
        free(name);
    }
    return (0);
}

int is_variable_word(char *line, int i)
{
    if (line[i] == '$' && !(is_blank(line[i + 1])) && !(is_finish(line[i + 1])))
        return (1);
    return (0);
}

int is_valide_argument(t_env *env, char *word)
{
    if (is_variable_word(word, 0) && !(is_variable(env, word, 0)))
        return (0);
    return (1);
}

int is_bin(t_env *env, char *word)
{
    char **bins;

    bins = get_env_bins(env);;
    if (test_absolute_bin_access(word))
        return (1);
    else if (test_bin_access(bins, word))
        return (1);
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

int is_standard_fd(int fd)
{
    if (fd == STDIN_FILENO || fd == STDOUT_FILENO || fd == STDERR_FILENO)
        return (1);
    return (0);
}

int is_not_standard_fd(int fd)
{
    if (fd != STDIN_FILENO && fd != STDOUT_FILENO && fd != STDERR_FILENO)
        return (1);
    return (0);
}

int cmd_have_standart_fd(t_cmd *cmd)
{
    if (is_standard_fd(cmd->fd_in) && is_standard_fd(cmd->fd_out))
        return (1);
    return (0);
}