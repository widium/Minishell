/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 15:20:41 by ebennace         ###   ########.fr       */
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

# include "minishell.h"

typedef struct s_token
{
    void *class;
    int id;
    int index;
    struct s_token *next;
    struct s_token *prev;

}   t_token;

typedef struct s_blank
{
    int             id;
	char			*content;

}   t_blank;

typedef struct s_word
{
    int             id;
	char			*content;

}   t_word;

typedef struct s_single
{
    int             id;
	char			*content;

}   t_single;

typedef struct s_double
{
    int             id;
	char			*content;

}   t_double;

typedef struct s_variable
{
	char			*content;

}   t_variable;

typedef struct s_redirection
{
    int fd_in;
    int fd_out;
    int type;
    char *limiter;
    char *content;

}   t_redirection;

typedef struct s_boolean
{
    char *content;
    char *first;
    char *second;
    int     id;

}   t_boolean;

typedef struct s_file
{
    char *name;
    int fd;

}   t_file;

typedef struct s_wildcard
{
    char *suffix;
    char *prefixe;

}   t_wildcard;

typedef struct s_arg
{
    char *content;
    int  id;
    int index;
    struct s_arg *next;
    struct s_arg *prev;
}   t_arg;

typedef struct s_cmd
{
    int             id;
    char            *content;
	char			*bin;
	char			**args;
    int             fd_in;
    int             fd_out;
    t_arg           *first_arg;

}   t_cmd;


t_token *init_token(void);
t_blank	*init_blank(char *content, int id);
t_word	*init_word(char *content, int id);
t_cmd   *init_cmd(char *content, int id);
t_file	*init_file(char *name, int fd);
t_single	*init_single(char *content, int id);
t_double	*init_double(char *content, int id);
t_variable	*init_variable(char *content);
t_redirection	*init_redirection(int type, char *content);
t_redirection	*init_heredoc(int type, char *content, char *limiter);
t_boolean	*init_boolean_operator(char * content, char *first, char *second, int id);
t_wildcard	*init_wildcard(void);
t_arg *init_arg(char *content, int id);


t_token *create_token(char *content, int id);
t_token *create_token_bool(char *content, char *first, char *second, int id);
t_token *create_token_redir(int type, char *content);
t_token *create_token_heredoc(int type, char *content, char *limiter);
t_token *create_token_variable(int id, char *content);
t_token *create_token_command(int id, char *content);
t_arg *create_arg(char *content, int id);
t_token *create_token_file(char *name, int fd, int id);

void *choose_class(char *content, int id);
void choose_arg_class(t_token *token, char *arg);
void connect_token(t_token *curr_token, t_token *next_token);
void connect_arg(t_arg *curr_arg, t_arg *next_arg);
void add_arg_list(t_cmd *cmd, t_arg *arg);

void *get_class(t_token *token);
char *get_content(t_token *token);
char *get_file_name(t_token *token);
int get_file_fd(t_token *token);

t_token *tokenizer(char *line, int start, int end, int id);
t_token *tokenizer_bool(char *line, int start, int end, int id);
t_token *tokenizer_redir(char *line, int start, int end, int id);
t_token *tokenizer_variable(char *line, int start, int end, int id);
t_token *tokenizer_command(char *word, int id);
t_arg *tokenizer_arg(char *line, int start, int end, int id);
t_token *tokenizer_file(char *name, int id);

int is_token_redirection(t_token *token);
int is_token_boolean(t_token *token);
int is_token_cmd(t_token *token);
int is_token_file(t_token *token);
int is_arg_variable(t_arg *arg);
int have_args(t_cmd *cmd);
int token_have_args(t_token *token);

void print_token(t_token *token);
void print_cmd(t_cmd *cmd, int index);
void print_args(t_cmd *cmd);
void print_redirection(t_token *token, t_redirection *redir);

t_arg *get_first_arg(t_cmd *cmd);

char **concatenate(t_cmd *cmd);

void remove_arg(t_arg *arg);
void disconect_arg(t_arg *arg);
void remove_all_arg(t_cmd *cmd);
void remove_arg_index(t_cmd *cmd, t_arg *arg);
void disconect_token(t_token *token);
void remove_token(t_token *token);
void remove_token_cmd(t_cmd *cmd);
void remove_token_redir(t_redirection *redir);
void remove_token_bool(t_boolean *boolean);
void remove_token_file(t_file *file);


t_token *command_classification(char *content, char *line, int index);
char *convert_id(int id);


# endif