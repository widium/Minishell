/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:37:24 by ebennace         ###   ########.fr       */
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
		create_history(env);
		
		parsing(env, env->line);
		// execution(env);
	}

}

void	create_history(t_env	*env)
{
	if (!(line_is_empty(env->line)))
	{
		add_history(env->line);
		write_line(env->line, env->history->fd);
	}
}

int	line_is_empty(char	*line)
{
	if (ft_strlen(line) == 0)
		return (1);
	else 
		return (0);
}

void	write_line(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	ft_putstr_fd("\n", fd);
}