/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:42:01 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 16:44:24 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_H
# define GET_H

# include "class.h"

char **get_bins(t_env *env);
char **get_list_of_bins(char *path_variable);

void *get_class(t_token *token);
char *get_content(t_token *token);
char *get_file_name(t_token *token);
int get_file_fd(t_token *token);
t_arg *get_first_arg(t_cmd *cmd);


void get_arg_variables_value(t_env *env);

t_token *get_first_token(t_env *env);
t_cmd *get_first_cmd(t_env *env);
char *get_variable_value(char **variables, char *var);

# endif