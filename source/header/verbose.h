/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:34:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/02 19:23:32 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOSE_H
# define VERBOSE_H

# include "class.h"

void	print_array_back_slash(char **str);
void	print_array(char **str);
void	print_array_fd(char **str, int fd);
void	print_array_index(char **str, int index);
void	print_args_array(char **args);	
void	print_str_index(char *str, int i);
void	print_chained_list(t_env *env);
void	print_variables(t_env *env);	
void	print_token(t_token *token);	
void	print_all_line(t_env *env);
void	print_line(t_line *line);
void	print_all_cmd_info(t_env *env);
void	print_all_env_var_struct(t_env *env);
void	print_env_var_struct(t_var *var);
void	print_all_env_export_var(t_env *env);
void	print_all_env_export_var_fd(t_env *env, int fd);
void	print_all_env_var(t_env *env);
void	print_all_env_var_fd(t_env *env, int fd);
void	print_env_var_fd(t_var *var, int fd);
void	print_env_var(t_var *var);
void	print_env_var_fd(t_var *var, int fd);
void	print_cmd(t_cmd *cmd, int index);
void	print_cmd_info(t_cmd *cmd);
void	print_args(t_cmd *cmd);	
void	print_redirection(t_token *token, t_redir *redir);
void	print_all_redirect_info(t_env *env);
void	print_redirect(t_token *tk, t_cmd *prv, t_cmd *nxt, t_file *file);
void	print_pipe_info(t_redir *redir, t_cmd *prev_cmd, t_cmd *next_cmd);
void	print_heredoc_info(t_redir *redir, t_cmd *prev_cmd);
void	print_input_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *file);
void	print_output_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *file);
void	print_append_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *file);

#endif