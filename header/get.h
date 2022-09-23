/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:42:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/23 18:33:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include "class.h"

char **get_bins(t_env *env);
char **get_list_of_bins(t_variable *vars, char *value);

int get_env_var_size(t_variable *variable);
char *get_env_var_value_with_name(t_variable *variable, char *name);
t_env_var *get_env_var_with_name(t_variable *variable, char *name);
t_env_var *get_last_env_var(t_variable *variable);
t_env_var *get_first_env_var(t_variable *vars);
void *get_class(t_token *token);
char *get_content(t_token *token);
char *get_file_name(t_token *token);
int get_file_fd(t_token *token);
t_line *get_first_line(t_env *env);
t_arg *get_first_arg(t_cmd *cmd);


void get_arg_variables_value(t_env *env);

t_token *get_first_token(t_env *env);
t_cmd *get_first_cmd(t_env *env);
char *get_export_variable_value(char *variable);
char *get_env_variable_value(char *variable);
char *get_variable_value(char **variables, char *var);
int same_name(char *first, char *second);
char *get_variable_name(char *variable);
int get_variable_index(char **variables, char *var);

char *get_cmd_path(t_cmd *cmd);
char **get_cmd_args(t_cmd *cmd);
int get_number_args(t_cmd *cmd);
t_arg *get_cmd_flags(t_cmd *cmd);

char **get_env_variables(t_env *env);
char **get_env_bins(t_env *env);
t_redirection *get_first_redirection(t_env *env);
t_token *get_first_token_redirection(t_env *env);
t_token *get_first_token_cmd(t_env *env);
t_token *get_first_token_built_in(t_env *env);

t_token *get_next_token_redirection(t_token *token);
t_token *get_next_token_cmd(t_token *token);
t_token *get_next_token_built_in(t_token *token);

int get_nbr_pipes(t_env *env);

t_cmd *get_prev_cmd(t_token *token);
t_cmd *get_next_cmd(t_token *token);
t_file *get_next_file(t_token *token);

char *get_home_path(t_env *env);
char *get_current_path(void);
char *get_parent_path(t_env *env);

char *get_rest_of_quote_content(char *line, int start, int end, char *quote);

# endif