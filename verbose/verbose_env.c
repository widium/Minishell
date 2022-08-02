/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:22:28 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 20:29:48 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_variables(t_variable *var)
{
    printf("\n======= VAR =====\n");
    print_array(var->variables);
    printf("\n======= PATH =====\n");
    printf("%s\n", var->path);
    printf("\n======= BINS =====\n");
    print_array(var->list_of_bin);
}