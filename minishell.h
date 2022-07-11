/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/11 17:43:20 by ebennace         ###   ########.fr       */
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
# include "token.h"
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

void    parsing(char *line);

int blank_detection(char *line, int index);
int double_quotes_detection(char *string, int i);
int single_quotes_detection(char *line, int index);
int word_detection(char *line, int index);
int variables_detection(char *line, int index);
void redirection_detection(char *str);
void boolean_detection(char *str);
void wildcard_detection(char *str);
void prefixe_wildcard_detection(char *line, int i);
void suffix_wildcard_detection(char *line, int i);
void built_in_detection(char *str);
void heredoc_detection(char *str);

void recover_keyword(char *str, int i);

int	is_in_str(char *first, int i, char *second);
int is_finish(char c);
int is_blank(char c);
int is_back_slash(char c);
int is_double_quote(char c);
int is_single_quote(char c);
int is_not_NULL(char c, char d);
int is_redirection(char *str, int i);
int is_boolean_operator(char *str, int i);
int is_doublons(char *str, int i, int c);
int is_heredoc(char *line, int i);
int is_separator(char *line, int i);
int is_word(char *line, int i);
int is_variable(char *line, int index);

void print_str_index(char *str, int i);
void print_detection(char *line, int start, int end, int token);
#endif