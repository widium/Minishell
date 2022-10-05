/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:27:22 by ebennace          #+#    #+#             */
/*   Updated: 2022/10/05 12:03:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_H
# define IS_H

# include "class.h"

int	is_in_str(char *first, int i, char *second);
int	variable_exist(t_env *env, char *variable);
int	is_finish(char c);
int	index_not_over_flow(char *line, int index);
int	index_is_over_flow(char *line, int index);
int	is_not_finish(char c);
int	line_is_finish(char *line, int index);
int	line_is_not_finish(char *line, int index);
int	is_blank_argument(t_env *env, char *line, int index);
int	is_blank(char c);
int	is_back_slash(char c);
int	is_double_quote(char c);
int	is_single_quote(char c);
int	is_quote(char c);
int	is_not_null(char c, char d);
int	is_value_null(char *value);
int	is_null(char *line);
int	is_input_chevrons(char *line, int i);
int	is_output_chevrons(char *line, int i);
int	is_pipe(char *line, int index);
int	is_append_chevrons(char *line, int i);
int	is_heredoc(char *line, int i);
int	is_file_redirection(char *line, int i);
int	is_redirection(char *line, int i);
int	is_and_operator(char *line, int i);
int	is_or_operator(char *line, int i);
int	is_doublons(char *str, int i, int c);
int	is_delimiter(t_env *env, char *line, int i);
int	is_variable_delimiter(char *line, int index);
int	is_valide_variable(t_env *env, char *word);
int	is_argument_separator(t_env *env, char *line, int index);
int	is_blank_before_redirection(char *line, int index);
int	is_blank_before_finish(char *line, int index);
int	is_separator(char *line, int i);
int	is_word(t_env *env, char *line, int i);
int	is_dollar_word(t_env *env, char *line, int i);
int	is_word_argument_separator(t_env *env, char *line, int index);
int	is_variable(t_env *env, char *line, int index);
int	is_variable_word(char *line, int i);
int	is_argument(char *line, int i);
int	is_flags(char *line, int i);
int	is_file(char *line, int i);
int	is_after_redirect(char *line, int index);
int	is_after_heredoc(char *line, int index);
int	is_limiter(char *line, int i);	
int	is_bin(t_env *env, char *word);
int	is_cmd(t_env *env, char *word);
int	is_built_in(char *content);	
int	is_token_redirection(t_token *token);
int	is_token_pipe(t_token *token);
int	is_token_heredoc(t_token *token);
int	is_token_input_chevron(t_token *token);
int	is_token_append_chevron(t_token *token);
int	is_token_output_chevron(t_token *token);
int	is_token_basic_redirection(t_token *token);
int	is_redir_heredoc(t_redir *redir);
int	is_token_boolean(t_token *token);
int	is_token_word(t_token *token);
int	is_token_cmd(t_token *token);
int	is_token_bin(t_token *token);
int	is_token_built_in(t_token *token);
int	is_cmd_bin(t_cmd *cmd);
int	is_cmd_built_in(t_cmd *cmd);
int	is_token_file(t_token *token);
int	is_arg_variable(t_arg *arg);
int	is_arg_flags(t_arg *arg);
int	is_arg_blank(t_arg *arg);	
int	is_echo(t_cmd *cmd);
int	is_cd(t_cmd *cmd);
int	is_pwd(t_cmd *cmd);
int	is_env(t_cmd *cmd);
int	is_export(t_cmd *cmd);
int	is_unset(t_cmd *cmd);
int	is_exit(t_cmd *cmd);	
int	cmd_have_args(t_cmd *cmd);
int	cmd_have_argument(t_cmd *cmd);
int	cmd_have_args_array(t_cmd *cmd);
int	cmd_have_arg_flags(t_cmd *cmd);
int	cmd_have_flags(t_cmd *cmd);
int	have_token_redirection(t_env *env);
int	have_token(t_env *env);
int	token_have_args(t_token *token);

#endif