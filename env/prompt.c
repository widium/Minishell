/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/22 17:49:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    prompt(t_env	*env)
{
	char *line;
	
	while (1)
	{
		use_signal();
		line = get_line(env);
		if (!line)
			break;
		create_history(env, line);
		parsing(env, line);
		check_error_parsing(env);
		if (env->error_parsing == 0)
		{
			processing_cmd(env);
			processing_redirection(env);
			if (env->error_processing == 0)
				execution(env);
		}
		reset_counter_error(env);
		remove_all_token(env);
		free(line);
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
	if (line_is_not_empty(line))
		create_history(env, line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);	
}

void reset_counter_error(t_env *env)
{
	env->error_parsing = 0;
	env->error_parsing = 0;
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