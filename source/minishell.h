/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 14:41:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFF_SIZE 4096

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "libft/libft.h"
# include "header/token.h"
# include "header/class.h"
# include "header/free.h"
# include "header/get.h"
# include "header/execution.h"
# include "header/is.h"
# include "header/verbose.h"

extern t_env	*g_env;

void		ask_verbose(t_env *env);
t_env		*init_env(char **varaibles);
t_var		*init_env_variable(char *name, char *value, int id);
t_line		*init_line(char *content);

void		recover_path_and_bins_variable(t_env *env, char **env_variable);
char		**add_env_variable(char **variables, char *var);
void		add_signal_env_var(t_env *env);
void		add_new_env_variable(t_env *env, t_var *new);
int			assign_env_var_id(char *value);
void		change_or_create_var(t_env *env, char *name, char *value, int id);
void		change_env_var_value_with_name(t_env *env, char *var, char *value);
void		change_env_var_value(t_var *var, char *new_value);
void		update_variable_status_process(t_env *env, int status);
int			convert_status_process_value(int status);
int			limiter_extraction(t_redir *redir, char *line, int index);

void		open_history_file(t_env	*env);

char		*get_line(void);
int			env_have_multi_line(t_env *env);
void		execute_line(t_env *env, char *line);
void		execute_multi_line(t_env *env, t_line *line);
void		prompt(t_env	*env);
void		create_history(char *line);
int			line_is_empty(char	*line);
int			line_is_not_empty(char	*line);

int			return_last_back_slash_index(char *str);

void		use_signal(void);
void		call_prompt(int key);
void		stop_prompt(int key);
void		pass(int key);
void		exit_prompt(int key);

void		write_line(char *line, int fd);

int			blank_detection(char *line, int index);
int			blank_escape(char *line, int index);
char		*variable_name_extraction(char *line, int index);
int			variable_detection(char *line, int index);
int			double_quotes_detection(char *string, int i);
int			single_quotes_detection(char *line, int index);
int			word_detection(t_env *env, char *line, int index);
int			word_arg_detection(t_env *env, char *line, int index);
int			limiter_detection(char *line, int index);
int			file_detection(char *line, int index);
int			redirection_detection(char *line, int index);
int			argument_extraction(t_env *env, t_cmd *cmd, char *line, int index);

void		double_tokenization(t_env *env, t_cmd *cmd, char *content);

int			double_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int			single_tokenizer(t_cmd *cmd, char *line, int index);
int			word_arg_extraction(t_env *env, t_cmd *cmd, char *line, int i);
int			variable_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int			variables_tokenization(t_env *env, t_cmd *cmd, char *line, int i);
int			string_extraction(t_env *env, t_cmd *cmd, char *line, int index);
int			blank_arg_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int			flags_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);

int			arg_classification(t_env *env, t_cmd *cmd, char *line, int index);
t_token		*cmd_classification(t_env *env, char *content);
int			word_classification(t_env *env, char *line, int index);
int			redirection_classification(t_env *env, char *line, int index);
int			arg_redirect_extraction(t_env *env, t_token *tok, char *lin, int i);

int			type_of_redirect(char *content);
int			type_of_boolean(char *content);

void		add_line_to_env(t_env *env, char *content);
void		parse_line_with_semicolon(t_env *env, char *line);
void		parsing(t_env *env, char *line);
void		processing_redirection(t_env *env);

void		add_variables_list(t_env *env, t_var *var);
void		add_token_list(t_env *env, t_token *token);

void		processing_cmd(t_env *env);
void		processing_bin(t_env *env);
void		processing_built_in(t_env *env);
void		choose_processing_built_in(t_env *env, t_cmd *cmd);
void		processing_exit(t_cmd *cmd);

void		processing_cd(t_env *env, t_cmd *cmd);
void		processing_echo(t_cmd *cmd);
void		processing_home_path(t_env *env, t_cmd *cmd);

void		processing_cmd_args(t_env *env);

void		concatenate_cmd_args(t_env *env);
void		change_arg_variable_content(t_env *env, t_arg *arg);

void		change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out);
int			is_standard_fd(int fd);
int			is_not_standard_fd(int fd);
int			cmd_have_standart_fd(t_cmd *cmd);
void		redirect_cmd(t_cmd *cmd);
void		open_next_file_with_flags(t_token *token, t_file *file);
void		manage_fd_for_redirection(t_token *token);
void		manage_fd_basic_redirection(t_token *token);
void		manage_fd_pipe(t_token *token);
void		manage_fd_heredoc(t_token *token);
char		*mini_get_next_line(int fd);
char		*heredoc_prompt(char *limiter);
char		*heredoc_not_finish(char *limiter);
int			compare_line(char *line, char *limiter, int fd_tmp);
char		*read_and_extract_content_file(char *path);

void		close_fd_cmd(t_cmd *cmd);
void		close_all_fd(t_env *env);
void		remove_tmp_file(t_token *token_heredoc);

int			wait_all_pid(t_env *env);
int			get_last_status(int bin_status, int ret_built_in);

int			doesnt_have_error_processing(t_env *env);
int			doesnt_have_error_parsing(t_env *env);
void		reset_counter_error(t_env *env);
void		check_error_parsing(t_env *env);
int			check_error_token_redirection(t_token *token);
int			check_error_token_heredoc(t_redir *redir);
int			check_error_token_basic_redirection(t_token *token, t_redir *redir);
int			check_error_token_pipe(t_token *token, t_redir *redir);
int			check_error_token_word(t_env *env, t_token *token);
int			check_error_token_cmd(t_token *token);
int			check_error_built_in(t_cmd *cmd);

int			check_error_echo(t_cmd *cmd);
int			check_error_cd(t_cmd *cmd);
int			check_error_pwd(t_cmd *cmd);
int			check_error_env(t_cmd *cmd);
int			check_error_unset(t_cmd *cmd);
int			check_error_export(t_cmd *cmd);
int			check_error_exit(t_cmd *cmd);

#endif