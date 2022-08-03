/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:03:36 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/03 12:42:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_cmd_info(t_cmd *cmd)
{
    printf(" ---[%s]---\n", cmd->content);
    printf(" | type : [%s]\n",convert_id(cmd->id));
    printf(" | path : [%s]\n",cmd->bin);
    printf(" | args : [");
    print_array(cmd->args);
    printf("]\n");
    printf(" | fd_in : [%d]\n",cmd->fd_in);
    printf(" | fd_out : [%d]\n",cmd->fd_out);
    printf(" --------\n");
}

