/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/07 14:04:30 by ebennace         ###   ########.fr       */
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

void ask_verbose(t_env *env);
t_env	*init_env(char **varaibles);
t_variable *init_variable(char **variables);

void recover_path_variable(t_variable *var, char **env_variable);
void change_variable_value(t_env *env, char *var, char *value);
void recover_keyword(char *str, int i);
int recover_limiter(t_redirection *redir, char *line, int index);

void open_history_file(t_env    *env);
char *convert_fd(int fd);

void    prompt(t_env	*env);
void	create_history(t_env	*env, char *line);
int	line_is_empty(char	*line);
int	line_is_not_empty(char	*line);

int return_last_back_slash_index(char *str);

void use_signal(void);
void call_prompt(int key);
void pass(int key);
void exit_prompt(int key);

void	write_line(char *line, int fd);

int blank_detection(char *line, int index);
int double_quotes_detection(char *string, int i);
int single_quotes_detection(char *line, int index);
int word_detection(char *line, int index);
int file_detection(char *line, int index);
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
t_token *command_classification(t_env *env, char *content);
int word_classification(t_env *env, char *line, int index);
int redirection_classification(t_env *env, char *line, int index);

int type_of_redirect(char *content);
int type_of_boolean(char *content);

char *return_built_in(char *content);

void parsing(t_env *env, char *line);
void processing_redirection(t_env *env);

void add_chained_list(t_env *env, t_token *token);

void processing_cmd(t_env *env);
void processing_bin(t_env *env);
void processing_built_in(t_env *env);
void choose_processing_built_in(t_env *env, t_cmd *cmd);

void processing_cd(t_env *env, t_cmd *cmd);
void processing_echo(t_cmd *cmd);
void processing_home_path(t_env *env, t_cmd *cmd);


void processing_cmd_args(t_env *env);

void concatenate_cmd_args(t_env *env);
void change_arg_variable_content(t_env *env, t_arg *arg);

void change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out);
int is_standard_fd(int fd);
int is_not_standard_fd(int fd);
int cmd_have_standart_fd(t_cmd *cmd);
void redirect_cmd(t_cmd *cmd);
void open_next_file_with_flags(t_token *token, t_file *file);
void manage_fd_for_redirection(t_token *token);
void manage_fd_basic_redirection(t_token *token);
void manage_fd_pipe(t_token *token);
void manage_fd_heredoc(t_token *token);
char *heredoc_prompt(char *limiter);

void close_fd(char *name, int fd);
void close_fd_cmd(t_cmd *cmd);
void close_all_fd(t_env *env);
void remove_tmp_file(t_token *token_heredoc);

void wait_all_pid(t_env *env);

void check_error_parsing(t_env *env);
int check_error_token_redirection(t_token *token);
int check_error_token_heredoc(t_token *token, t_redirection *redir);
int check_error_token_basic_redirection(t_token *token, t_redirection *redir);
int check_error_token_pipe(t_token *token, t_redirection *redir);
int check_error_token_word(t_token *token);
int check_error_token_cmd(t_token *token);
int check_error_built_in(t_cmd *cmd);

int check_error_echo(t_cmd *cmd);
int check_error_cd(t_cmd *cmd);
int check_error_pwd(t_cmd *cmd);
int check_error_env(t_cmd *cmd);
int check_error_unset(t_cmd *cmd);
int check_error_export(t_cmd *cmd);
int check_error_exit(t_cmd *cmd);

#endif