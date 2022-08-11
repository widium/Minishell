/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 16:52:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

#include "class.h"

void ft_exit(t_env *env);

void free_all(t_env *env);
void my_free(void **ptr);

void remove_all(t_env *env);
void remove_all_token(t_env *env);
void remove_arg(t_arg *arg);
void remove_all_arg(t_cmd *cmd);
void remove_arg_index(t_cmd *cmd, t_arg *arg);
void remove_token(t_token *token);
void remove_token_cmd(t_cmd *cmd);
void remove_token_redir(t_redirection *redir);
void remove_token_bool(t_boolean *boolean);
void remove_token_file(t_file *file);

void disconect_arg(t_arg *arg);
void disconect_token(t_token *token);

# endif