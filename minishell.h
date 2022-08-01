/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:58:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 16:23:22 by ebennace         ###   ########.fr       */
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

typedef struct s_err
{
	int	exit;
} 		t_err;

typedef struct s_env
{
	int		nbr_cmd;
	char	*line;
	char	**variables;
	t_err	*error;
	t_file	*history;
	t_token *first_token;
}   t_env;

t_err	*init_err(void);
t_env	*init_env(char **varaibles);

void open_files(t_env    *env);
char *get_variable_value(char **env, char *variable);
char *extract_value_variable(char *env, char *variable);

void    prompt(t_env	*env);
void	create_history(t_env	*env);
int	line_is_empty(char	*line);

void use_signal(t_env *env, int key);
void exit_prompt(int key);

void	write_line(char *line, int fd);

void ft_exit(t_env *env);

void remove_all(t_env *env);
void remove_all_token(t_env *env);
void free_all(t_env *env);
void my_free(void **ptr);

int blank_detection(char *line, int index);
int double_quotes_detection(char *string, int i);
int double_quotes_extraction(t_cmd * cmd, char *line, int index);
int single_quotes_detection(char *line, int index);
int single_quotes_extraction(t_cmd *cmd, char *line, int index);
int word_detection(char *line, int index);
int word_argument_extraction(t_cmd *cmd, char *line, int index);
int redirection_detection(char *line, int index);
int variables_extraction(t_cmd *cmd, char *line, int index);
int string_extraction(t_cmd *cmd, char *line, int index);
int paranthesis_detection(char *line, int index);
void parse_double_quote(t_cmd *cmd, char *content);

int boolean_detection(char *line, int index);
int boolean_classification(t_env *env, char *line, int index);

void wildcard_detection(char *str);
void prefixe_wildcard_detection(char *line, int i);
void suffix_wildcard_detection(char *line, int i);

void heredoc_detection(char *str);

void recover_keyword(char *str, int i);

int	is_in_str(char *first, int i, char *second);
int is_finish(char c);
int is_blank(char c);
int is_back_slash(char c);
int is_double_quote(char c);
int is_single_quote(char c);
int is_quote(char c);
int is_not_NULL(char c, char d);
int is_input_chevrons(char *line, int i);
int is_output_chevrons(char *line, int i);
int is_pipe(char *line, int index);
int is_append_chevrons(char *line, int i);
int is_heredoc(char *line, int i);
int is_file_redirection(char *line, int i);
int is_redirection(char *line, int i);
int is_boolean_operator(char *line, int i);
int is_and_operator(char *line, int i);
int is_or_operator(char *line, int i);
int is_doublons(char *str, int i, int c);
int is_delimiter(char *line, int i);
int is_separator(char *line, int i);
int is_word(char *line, int i);
int is_variable(char *line, int index);
int is_paranthesis(char *line, int index);
int is_in_double_quote(char *line, int index);
int is_in_single_quote(char *line, int index);
int is_in_quote(char *line, int index);
int is_argument(char *line, int i);
int is_bin(char *word);
int is_cmd(char *word);
int is_flags(char *line, int i);
int is_file(char *line, int i);
int is_after_redirect(char *line, int index);
int is_after_heredoc(char *line, int index);
int is_limiter(char *line, int i);

int recover_limiter(t_redirection *redir, char *line, int index);

int type_of_redirect(char *content);
int type_of_boolean(char *content);

int is_built_in_index(char *line, int index);
int is_built_in(char *content);
char *return_built_in(char *content);
int argument_detection(t_cmd *cmd, char *line, int index);
int argument_classification(t_cmd *cmd, char *line, int index);
int flags_extraction(t_cmd *cmd, char *line, int index);

void print_array(char **str);
void print_args_array(char **args);
void print_str_index(char *str, int i);
void print_detection(char *line, int start, int end, int token);
void print_chained_list(t_env *env);

void parsing(t_env *env, char *line);
int word_classification(t_env *env, char *line, int index);
int redirection_classification(t_env *env, char *line, int index);
void add_chained_list(t_env *env, t_token *token);

void concatenate_args(t_env *env);
void change_arg_content(t_env *env, t_arg *arg);
void get_variables_value(t_env *env);


t_token *get_first_token(t_env *env);
int tokenization(t_env *env, char *line, int index);

#endif