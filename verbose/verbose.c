/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:50:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/10 18:14:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void ask_verbose(t_env *env)
{
	char answer;
	
	printf("Minishell mode verbose [Y/N] ?");
	scanf("%c", &answer);
	if (answer == 'Y')
	{
		printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	else if (answer == 'N')
		env->verbose = 0;
}

void print_detection(char *line, int start, int end, int token)
{
    printf("DETECTION : [");
    while (line[start] && start <= end)
    {
        printf("%c", line[start]);
        start++;
    }
    printf("]\n");
    
}

void print_array_back_slash(char **str)
{
    int i;

    if (!str)
        return;
    i = 0;
    while(str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
}

void print_array(char **str)
{
    int i;

    if (!str)
        return;
    i = 0;
    while(str[i])
    {
        printf("%s ", str[i]);
        i++;
    }
}

void print_array_fd(char **str, int fd)
{
    int i;

    if (!str)
        return;
    i = 0;
    while(str[i])
    {
        ft_putstr_fd(str[i], fd);
        ft_putstr_fd("\n", fd);
        i++;
    }
}
void print_array_index(char **str, int index)
{

    if (!str)
        return;
    while(str[index])
    {
        printf("%s ", str[index]);
        index++;
    }
}

void print_str_index(char *str, int i)
{
    while (str[i])
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}


char *convert_id(int id)
{
    if (id == TOKEN_NULL)
        return ("TOKEN_NULL");
    if (id == TOKEN_BLANK)
        return ("TOKEN_BLANK");
    if (id == TOKEN_WORD)
        return ("TOKEN_WORD");
    if (id == TOKEN_SINGLE_QUOTE)
        return ("TOKEN_SINGLE_QUOTE");
    if (id == TOKEN_DOUBLE_QUOTE)
        return ("TOKEN_DOUBLE_QUOTE");
    if (id == TOKEN_PARANTHESIS)
        return ("TOKEN_PARANTHESIS");
    if (id == TOKEN_REDIRECTION)
        return ("TOKEN_REDIRECTION");
    if (id == TOKEN_COMMAND)
        return ("TOKEN_COMMAND");
    if (id == TOKEN_BUILT_IN)
        return ("TOKEN_BUILT_IN");
    if (id == TOKEN_BINARY)
        return ("TOKEN_BINARY");
    if (id == TOKEN_FLAGS)
        return ("TOKEN_FLAGS");
    if (id == TOKEN_ARGUMENT)
        return ("TOKEN_ARGUMENT");
    if (id == TOKEN_VARIABLE)
        return ("TOKEN_VARIABLE");
    if (id == TOKEN_FILE)
        return ("TOKEN_FILE");
    if (id == TOKEN_AND)
        return ("TOKEN_AND");
    if (id == TOKEN_OR)
        return ("TOKEN_OR");
    if (id == TOKEN_WILDCARD)
        return ("TOKEN_WILDCARD");
    if (id == TOKEN_PIPE)
        return ("TOKEN_PIPE");
    if (id == TOKEN_INPUT_CHEVRON)
        return ("TOKEN_INPUT_CHEVRON");
    if (id == TOKEN_OUTPUT_CHEVRON)
        return ("TOKEN_OUTPUT_CHEVRON");
    if (id == TOKEN_APPEND_CHEVRON)
        return ("TOKEN_APPEND_CHEVRON");
    if (id == TOKEN_HERE_DOC)
        return ("TOKEN_HERE_DOC");
    if (id == TOKEN_BOOLEAN)
        return ("TOKEN_BOOLEAN"); 
    if (id == TOKEN_LIMITER)
        return ("TOKEN_LIMITER");
    if (id == TOKEN_STRING)
        return ("TOKEN_STRING");
    if (id == TOKEN_NOT_FINISH)
        return ("TOKEN_NOT_FINISH");
    return ("NULL");
}

