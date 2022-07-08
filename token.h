/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/08 18:31:19 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define BLANK 0
# define WORD 2
# define COMMAND 3
# define BUILT_IN 4
# define BINARY 5
# define FLAGS 6
# define ARGUMENT 7
# define VARIABLE 8
# define FILE_ 9
# define SINGLE_QUOTE 10
# define DOUBLE_QUOTE 11
# define AND 12
# define OR 13
# define WILDCARD 14
# define REDIRECTION 15
# define PIPE 16
# define CHEVRON 17
# define HERE_DOC 18
# define PARANTHESIS 19

# include "minishell.h"


# endif