/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/14 11:20:11 by ebennace         ###   ########.fr       */
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

typedef struct s_token
{
    int index;
    int id;
    char *content;
    struct s_token *prev;
    struct s_token *next;

}   t_token;

t_token *init_token(void);
t_token *create_token(char *content, int id);
void connect_token(t_token *curr_token, t_token *next_token);

t_token *tokenizer(char *line, int start, int end, int id);

void print_token(t_token *token);
char *convert_id(int id);

# endif