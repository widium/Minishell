/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/04 17:47:04 by ebennace         ###   ########.fr       */
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
# include "header/token.h"
# include "header/class.h"
# include "header/free.h"
# include "header/get.h"
# include "header/execution.h"
# include "header/is.h"
# include "header/verbose.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

t_err	*init_err(void);
t_env	*init_env(char **varaibles);
t_variable *init_variable(char **variables);

void recover_path_variable(t_variable *var, char **env_variable);
void recover_keyword(char *str, int i);
int recover_limiter(t_redirection *redir, char *line, int index);

void open_files(t_env    *env);
char *convert_fd(int fd);

void    prompt(t_env	*env);
void	create_history(t_env	*env);
int	line_is_empty(char	*line);

void use_signal(t_env *env, int key);
void exit_prompt(int key);

void	write_line(char *line, int fd);

int blank_detection(char *line, int index);
int double_quotes_detection(char *string, int i);
int single_quotes_detection(char *line, int index);
int word_detection(char *line, int index);
int redirection_detection(char *line, int index);
int paranthesis_detection(char *line, int index);
void wildcard_detection(char *str);
void prefixe_wildcard_detection(char *line, int i);
void suffix_wildcard_detection(char *line, int i);
int boolean_detection(char *line, int index);
void heredoc_detection(char *str);
int argument_detection(t_cmd *cmd, char *line, int index);

void parse_double_quote(t_cmd *cmd, char *content);

char *extract_value_variable(char *env, char *variable);
int double_quotes_extraction(t_cmd * cmd, char *line, int index);
int single_quotes_extraction(t_cmd *cmd, char *line, int index);
int word_argument_extraction(t_cmd *cmd, char *line, int index);
int variables_extraction(t_cmd *cmd, char *line, int index);
int string_extraction(t_cmd *cmd, char *line, int index);
int flags_extraction(t_cmd *cmd, char *line, int index);

int boolean_classification(t_env *env, char *line, int index);
int argument_classification(t_cmd *cmd, char *line, int index);
t_token *command_classification(t_env *env, char *content, char *line, int index);
int word_classification(t_env *env, char *line, int index);
int redirection_classification(t_env *env, char *line, int index);

int type_of_redirect(char *content);
int type_of_boolean(char *content);

char *return_built_in(char *content);

void parsing(t_env *env, char *line);

void add_chained_list(t_env *env, t_token *token);

void concatenate_args(t_env *env);
void change_arg_content(t_env *env, t_arg *arg);






#endif