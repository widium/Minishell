/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:34:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/04 15:34:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_H
# define VERBOSE_H

# include "class.h"

void print_array_back_slash(char **str);
void print_array(char **str);
void print_array_index(char **str, int index);
void print_args_array(char **args);

void print_str_index(char *str, int i);
void print_detection(char *line, int start, int end, int token);

void print_chained_list(t_env *env);
void print_variables(t_variable *var);

void print_token(t_token *token);

void print_all_cmd_info(t_env *env);
void print_cmd(t_cmd *cmd, int index);
void print_cmd_info(t_cmd *cmd);
void print_args(t_cmd *cmd);

void print_redirection(t_token *token, t_redirection *redir);
void print_all_redirect_info(t_env *env);
void print_redirect_info(t_token *token, t_cmd *prev_cmd, t_cmd *next_cmd, t_file *next_file);
void print_pipe_info(t_redirection *redir, t_cmd *prev_cmd, t_cmd *next_cmd);
void print_heredoc_info(t_redirection *redir, t_cmd *prev_cmd);
void print_input_chevron_info(t_redirection *redir, t_cmd *prev_cmd, t_file *next_file);
void print_output_chevron_info(t_redirection *redir, t_cmd *prev_cmd, t_file *next_file);
void print_append_chevron_info(t_redirection *redir, t_cmd *prev_cmd, t_file *next_file);


# endif