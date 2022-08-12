/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:37:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/12 16:49:04 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

typedef struct s_varaible
{
	char **variables;
	char *path;
	char **bins;
} 		t_variable;

typedef struct s_err
{
	int	exit;
} 		t_err;

typedef struct s_token
{
    void *class;
    int id;
    int index;
    struct s_token *next;
    struct s_token *prev;

}   t_token;

typedef struct s_file
{
    char *name;
    int fd;

}   t_file;

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


typedef struct s_redirection
{
    int fd_in;
    int fd_out;
    int type;
    char *limiter;
    char *content;
    t_file *tmp_file;

}   t_redirection;

typedef struct s_boolean
{
    char *content;
    char *first;
    char *second;
    int     id;

}   t_boolean;

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
    int             pid;

}   t_cmd;

typedef struct s_env
{
    int     error_parsing;
	int		nbr_cmd;
	t_variable *variable;
	t_err	*error;
	t_file	*history;
	t_token *first_token;
}   t_env;

# endif