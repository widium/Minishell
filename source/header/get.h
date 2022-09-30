/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:42:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/29 12:53:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include "class.h"

char	**get_bins(t_env *env);
char	**get_list_of_bins(t_env *env);

int		get_env_var_size(t_env *env);
char	*get_env_var_value_with_name(t_env *env, char *name);
t_var	*get_env_var_with_name(t_env *env, char *name);
t_var	*get_last_env_var(t_env *env);
t_var	*get_first_env_var(t_env *env);
void	*get_class(t_token *token);
t_line	*get_first_line(t_env *env);
t_arg	*get_first_arg(t_cmd *cmd);

void	get_arg_variables_value(t_env *env);

t_token	*get_first_token(t_env *env);
t_cmd	*get_first_cmd(t_env *env);
char	*get_env_variable_value(char *variable);
char	*get_export_variable_name(char *variable);
char	*get_env_variable_value(char *variable);
int		same_name(char *first, char *second);
char	*get_variable_name(char *variable);

char	*get_cmd_path(t_cmd *cmd);
char	**get_cmd_args(t_cmd *cmd);
int		get_number_args(t_cmd *cmd);
t_arg	*get_cmd_flags(t_cmd *cmd);

char	**get_env_variables(t_env *env);
char	**get_env_bins(t_env *env);
t_redir	*get_first_redirection(t_env *env);
t_token	*get_first_token_redirection(t_env *env);
t_token	*get_first_token_cmd(t_env *env);
t_token	*get_first_token_built_in(t_env *env);
t_token	*get_first_token_bin(t_env *env);

t_token	*get_next_token_redirection(t_token *token);
t_token	*get_next_token_cmd(t_token *token);
t_token	*get_next_token_built_in(t_token *token);
t_token	*get_next_token_bin(t_token *token);

int		get_nbr_pipes(t_env *env);

t_cmd	*get_prev_cmd(t_token *token);
t_cmd	*get_next_cmd(t_token *token);
t_file	*get_next_token_file(t_token *token);

char	*get_home_path(t_env *env);
char	*get_current_path(void);
char	*get_last_path(t_env *env);

char	*get_rest_single_quote(char *line, int start, int end, char *quote);

#endif