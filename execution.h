/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:29:42 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 16:44:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "class.h"

int test_bin_access(char **bins, char *word);
int test_absolute_bin_access(char *path);

void setup_bin_path(t_cmd *cmd, char **bins);
char *create_path_bin(char **bins, char *cmd);

void execution(t_env *env);
void bin_execution(t_env *env, t_cmd *cmd);

# endif