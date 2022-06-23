/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/23 12:25:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <signal.h>

# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	int				index;
	char			*brut;
	char			*bin;
	char			*flags;
	char			**complete;
	struct s_cmd	*next_cmd;
}   t_cmd;

typedef struct s_file
{
	int		fd;
	char	*name;
}	t_file;

typedef struct s_err
{
	int	exit;
} 		t_err;

typedef struct s_env
{
	int		nbr_cmd;
	char	*line;
	t_err	*error;
	t_file	*history;
	t_cmd	*first_cmd;
}   t_env;

t_err	*init_err(void);
t_cmd   *init_cmd(void);
t_file	*init_file(void);
t_env	*init_env(void);

void open_files(t_env    *env);

void    prompt(t_env	*env);
void	create_history(t_env	*env);
int	line_is_empty(char	*line);

void use_signal(t_env *env, int key);
void exit_prompt(int key);

void	write_line(char *line, int fd);

void ft_exit(t_env *env);

void free_all(t_env *env);

#endif