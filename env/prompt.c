/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/11 16:03:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    prompt(t_env	*env)
{
	char *line;
	
	use_signal(env, 0);
	while (1)
	{
		env->line = readline("$> ");
		if (line_is_not_empty(env->line))
		{
			create_history(env);
			parsing(env, env->line);
			processing_redirection(env);
			execution(env);
			remove_all_token(env);
		}
	}

}

void	create_history(t_env	*env)
{
	add_history(env->line);
	open_history_file(env);
	write_line(env->line, env->history->fd);
}

void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}