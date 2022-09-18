/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/18 18:11:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TOKEN_NULL 0
# define TOKEN_BLANK 1
# define TOKEN_WORD 2
# define TOKEN_SINGLE_QUOTE 3
# define TOKEN_DOUBLE_QUOTE 4
# define TOKEN_PARANTHESIS 5
# define TOKEN_COMMAND 6
# define TOKEN_BUILT_IN 7
# define TOKEN_BINARY 8
# define TOKEN_FLAGS 9
# define TOKEN_ARGUMENT 10
# define TOKEN_VARIABLE 11
# define TOKEN_FILE 12
# define TOKEN_AND 13
# define TOKEN_OR 14
# define TOKEN_WILDCARD 15
# define TOKEN_REDIRECTION 16
# define TOKEN_PIPE 17
# define TOKEN_INPUT_CHEVRON 18
# define TOKEN_OUTPUT_CHEVRON 19
# define TOKEN_APPEND_CHEVRON 20
# define TOKEN_HERE_DOC 21
# define TOKEN_BOOLEAN 22
# define TOKEN_LIMITER 23
# define TOKEN_STRING 24
# define TOKEN_NOT_FINISH 25

# include "class.h"

t_token *init_token(void);
t_blank	*init_blank(char *content, int id);
t_word	*init_word(char *content, int id);
t_cmd   *init_cmd(char *content, int id);
t_file	*init_file(char *name, int fd);
t_single	*init_single(char *content, int id);
t_double	*init_double(char *content, int id);
t_redirection	*init_redirection(int type, char *content);
t_redirection	*init_heredoc(int type, char *content, char *limiter);
t_boolean	*init_boolean_operator(char * content, char *first, char *second, int id);
t_wildcard	*init_wildcard(void);
t_arg *init_arg(char *content, int id);

t_env_var *create_chained_var(t_variable *variable, char **env_variable);
t_token *create_token_word(char *content, int id);
t_token *create_token_bool(char *content, char *first, char *second, int id);
t_token *create_token_redir(char *line, int index, int new_index);
t_token *create_token_heredoc(int type, char *content, char *limiter);
t_token *create_token_variable(int id, char *content);
t_token *create_token_command(int id, char *content);
t_arg *create_arg(char *content, int id);
t_token *create_token_file(char *name, int fd, int id);
int next_file_tokenization(t_env *env, char *line, int index);

void *choose_class(char *content, int id);
void choose_arg_class(t_token *token, char *arg);
void connect_new_var(t_env_var *prev_var, t_env_var *curr_var, t_env_var *next_var);
void connect_var(t_env_var *curr_var, t_env_var *next_var);
void connect_token(t_token *curr_token, t_token *next_token);
void connect_arg(t_arg *curr_arg, t_arg *next_arg);
void add_arg_list(t_cmd *cmd, t_arg *arg);

void tokenization(t_env *env, char *line);
int tokenize_content_single_quote(t_cmd *cmd, char *line, int start, int index);
char *get_content_double_quote(t_cmd *cmd, char *line, int start, int *index);
t_token *tokenizer_word(char *content, int id);
int command_tokenization(t_env *env, char *line, char *content, int index);
t_token *tokenizer_bool(char *line, int start, int end, int id);
t_token *tokenizer_command(char *word, int id);
t_arg *tokenizer_arg(char *line, int start, int end, int id);
void tokenize_word_arg(t_env *env, t_cmd *cmd, char *content);
t_token *tokenizer_file(char *name, int id);

int size_of_list(t_cmd *cmd);

char **list_to_array(t_cmd *cmd);
char *list_to_string(t_cmd *cmd);


char *convert_id(int id);

# endif