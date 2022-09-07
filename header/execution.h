/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:29:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/07 13:13:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "class.h"

int test_bin_access(char **bins, char *word);
int test_absolute_bin_access(char *path);

void setup_bin_path(t_cmd *cmd, char **bins);
void setup_bin_args(t_cmd *cmd, char **bins);
char *extract_bin_name_in_path(char *path);
char *create_path_bin(char **bins, char *cmd);
char **append_bin_name_in_args(char **args, char *name);

void execution(t_env *env);
void bin_execution(t_env *env, t_cmd *cmd);
void built_in_execution(t_env *env, t_cmd *cmd);

void echo(t_cmd *cmd);
void cd(t_cmd *cmd, t_env *env);
void env_built_in(t_cmd *cmd, t_env *env);
void export_built_in(t_cmd *cmd, t_env *env);
void unset(t_cmd *cmd, t_env *env);
void pwd(t_cmd *cmd, t_env *env);
void exit_built_in(int signal);

# endif