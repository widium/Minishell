/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:46:10 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 07:59:58 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "class.h"	

void	remove_var_list(t_env *env);
void	free_env_var(t_var *var);
void	remove_and_disconect_env_var(t_env *env, t_var *var);
void	remove_all(t_env *env);
void	remove_env_vars(t_env *env);
void	remove_all_token(t_env *env);
void	remove_blank_arg(t_cmd *cmd);
void	remove_arg(t_arg *arg);
void	remove_arg_in_cmd(t_cmd *cmd, t_arg *arg);
void	remove_all_arg(t_cmd *cmd);
void	remove_arg_index(t_cmd *cmd, t_arg *arg);
void	remove_token(t_token *token);
void	remove_token_cmd(t_cmd *cmd);
void	remove_token_redir(t_redir *redir);
void	remove_token_word(t_word *word);
void	remove_token_file(t_file *file);
void	remove_line(t_line *line);
void	remove_all_line(t_env *env);
void	remove_variable(t_env *env);
void	remove_env_var(t_var *var);	
void	disconect_line(t_line *current_line);
void	disconect_arg(t_arg *arg);
void	disconect_env_var(t_env *env, t_var *var);
void	disconect_env_var_first(t_env *env, t_var *var, t_var *var_next);
void	disconect_token(t_token *token);

#endif