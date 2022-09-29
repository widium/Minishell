/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:37:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 17:22:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_H
# define CLASS_H

# define VALUE 1
# define NONE_VALUE 2

typedef struct s_line
{
	int				index;
	char			*content;
	struct s_line	*next;
	struct s_line	*prev;

}	t_line;

typedef struct s_var
{
	int				index;
	int				id;
	char			*name;
	char			*value;
	struct s_var	*next;
	struct s_var	*prev;

}	t_var;

typedef struct s_token
{
	void			*class;
	int				id;
	int				index;
	struct s_token	*next;
	struct s_token	*prev;

}	t_token;

typedef struct s_file
{
	char	*name;
	int		fd;

}	t_file;

typedef struct s_blank
{
	int				id;
	char			*content;

}	t_blank;

typedef struct s_word
{
	int				id;
	char			*content;

}	t_word;

typedef struct s_redir
{
	int		fd_in;
	int		fd_out;
	int		type;
	char	*limiter;
	char	*content;
	t_file	*tmp_file;

}	t_redir;

typedef struct s_arg
{
	char			*content;
	int				id;
	int				index;
	struct s_arg	*next;
	struct s_arg	*prev;
}	t_arg;

typedef struct s_cmd
{
	int		id;
	char	*content;
	char	*flags;
	char	*bin;
	char	**args;
	char	*arg;
	int		fd_in;
	int		fd_out;
	t_arg	*first_arg;
	int		pid;

}	t_cmd;

typedef struct s_env
{
	int			verbose;
	int			error_parsing;
	int			error_processing;
	char		**env_vars;
	t_line		*first_line;
	t_token		*first_token;
	t_var		*first_var;

}	t_env;

#endif