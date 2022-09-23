/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 13:09:42 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    prompt(t_env	*env)
{
	char *read_line;
	t_line *line;
	
	while (1)
	{
		use_signal();
		read_line = get_line(env);
		if (!read_line)
		{
			printf("exit\n");
			break;
		}
		parse_line_with_semicolon(env, read_line);
		free(read_line);
		line = get_first_line(env);
		while (line)
		{
			execute_line(env, line->content);
			line = line->next;
		}
	}
}

void execute_line(t_env *env, char *line)
{
	parsing(env, line);
	check_error_parsing(env);
	if (doesnt_have_error_parsing)
	{
		processing_cmd(env);
		processing_redirection(env);
		if (doesnt_have_error_processing)
			execution(env);
	}
	reset_counter_error(env);
	remove_all_token(env);
}

void parse_line_with_semicolon(t_env *env, char *line)
{
    int index;
    int start;
    int end;
    char *sub_line;

    index = 0;
    start = index;
    while (line[index])
    {
        if (line[index] == ';' || is_finish(line[index + 1]))
        {
			if (is_finish(line[index + 1]))
            	end = index;
			else
				end = index - 1;
            sub_line = malloc_substrcpy(line, start, (end - start) + 1);
			add_line_to_env(env, sub_line);
			start = index + 1;
        }
        index++;
    }
}

char *get_line(t_env *env)
{
	struct termios	saved;
	struct termios	attributes;
	char *line;
	
	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	line = readline("$> ");
	if (is_NULL(line))
		return (NULL);
	create_history(env, line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);
}

void reset_counter_error(t_env *env)
{
	env->error_parsing = 0;
}

int doesnt_have_error_parsing(t_env *env)
{
	if (env->error_parsing == 0)
		return (1);
	return (0);
}

int doesnt_have_error_processing(t_env *env)
{
	if (env->error_processing == 0)
		return (1);
	return (0);
}

void	create_history(t_env *env, char *line)
{
	add_history(line);
	open_history_file(env);
	write_line(line, env->history->fd);
}

void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}