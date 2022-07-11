/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/11 18:11:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define TOKEN_BLANK 1
# define TOKEN_WORD 2
# define TOKEN_COMMAND 3
# define TOKEN_BUILT_IN 4
# define TOKEN_BINARY 5
# define TOKEN_FLAGS 6
# define TOKEN_ARGUMENT 7
# define TOKEN_VARIABLE 8
# define TOKEN_FILE 9
# define TOKEN_SINGLE_QUOTE 10
# define TOKEN_DOUBLE_QUOTE 11
# define TOKEN_AND 12
# define TOKEN_OR 13
# define TOKEN_WILDCARD 14
# define TOKEN_REDIRECTION 15
# define TOKEN_PIPE 16
# define TOKEN_CHEVRON 17
# define TOKEN_HERE_DOC 18
# define TOKEN_PARANTHESIS 19

# include "minishell.h"

typedef struct s_token
{
    int id;
    char *content;
    struct s_token *prev;
    struct s_token *next;

}   t_token;

t_token *init_token(void);
t_token *create_token(char *content, int id);

void tokenization(char *line);
t_token *tokenizer(char *line, int start, int end, int id);

void print_token(t_token *token);

# endif