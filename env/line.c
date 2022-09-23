/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:27:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 12:58:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"


void print_all_line(t_env *env)
{
    t_line *line;
    
    line = get_first_line(env);
    while (line)
    {
        print_line(line);
        line = line->next;
    }
}

void print_line(t_line *line)
{
    printf("Line [%d] : [%s]\n", line->index, line->content);
}

t_line	*init_line(char *content)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->index = -1;
	line->content = content;
    line->next = NULL;
    line->prev = NULL;
	return (line);
}

void add_line_to_env(t_env *env, char *content)
{
	t_line *line;
	
	line = init_line(content);
	add_line_list(env, line);
}

void add_line_list(t_env *env, t_line *line)
{
    t_line *iter;
    int i;
    
    i = 1;
    if (!(env->first_line))
    {
        env->first_line = line;
        line->index = i;
    }
    else 
    {
        iter = env->first_line;
        i++;
        while (iter->next)
        {
            i++;
            iter = iter->next;
        }
        line->index = i;
        connect_line(iter, line);
    }
}

void connect_line(t_line *curr_line, t_line *next_line)
{
	curr_line->next = next_line;
	next_line->prev = curr_line;
}