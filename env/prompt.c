/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/07 14:02:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    prompt(t_env	*env)
{
	char *line;
	
	while (1)
	{
		use_signal();
		line = readline("$> ");
		if (line_is_not_empty(line))
		{
			create_history(env, line);
			parsing(env, line);
			if (env->error_parsing == 0)
			{
				processing_cmd(env);
				processing_redirection(env);
				execution(env);
			}
			remove_all_token(env);
			free(line);
		}
	}

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