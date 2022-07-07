/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:17:13 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/07 14:58:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void    prompt(t_env	*env)
{	
	use_signal(env, 0);
	while (1)
	{
		env->line = readline("$> ");
		create_history(env);
		// parsing(env->line);
		// word_detection(env->line);
		built_in_detection(env->line);
		heredoc_detection(env->line);
		double_quotes_detection(env->line);
		single_quotes_detection(env->line);
		variables_detection(env->line);
		redirection_detection(env->line);
		boolean_detection(env->line);
		wildcard_detection(env->line);
		
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