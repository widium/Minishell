/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 17:23:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

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

# include "minishell.h"


// typedef union s_Token
// {
//     t_blank blank;
//     t_word word;
//     t_single single;
//     t_double double_q;
//     t_boolean boolean;
//     t_variable variable;
//     t_file file;
//     t_redirection redirection;
//     t_wildcard wildcard;
//     t_cmd cmd;
// } t_Token;


typedef struct s_token
{
    void *class;
    int id;
    struct s_token *next;
    struct s_token *prev;

}   t_token;

// typedef struct s_token
// {
//     int index;
//     int id;
//     char *content;
//     struct s_token *next;
//     struct s_token *prev;

// }   t_token;

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
    int             id;
	char			*content;

}   t_variable;

typedef struct s_redirection
{
    int fd_in;
    int fd_out;
    int id;

}   t_redirection;

typedef struct s_boolean
{
    char *in;
    char *out;
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

typedef struct s_cmd
{
    int             id;
	char			*bin;
	char			*flags;
	char			**complete;
    int             fd_in;
    int             fd_out;

}   t_cmd;


t_token *init_token(void);
t_blank	*init_blank(char *content, int id);
t_word	*init_word(char *content, int id);
t_cmd   *init_cmd(void);
t_file	*init_file(void);
t_single	*init_single(void);
t_double	*init_double(void);
t_variable	*init_variable(void);
t_redirection	*init_redirection(void);
t_boolean	*init_boolean_operator(void);
t_wildcard	*init_wildcard(void);



t_token *create_token(char *content, int id);
t_token *word_classfication(char *line, char *content, int index);
void *choose_class(char *content, int id);
void connect_token(t_token *curr_token, t_token *next_token);
char *get_content(t_token *token);

t_token *tokenizer(char *line, int start, int end, int id);

void print_token(t_token *token);
char *convert_id(int id);

# endif