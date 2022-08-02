/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:22:03 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/02 16:22:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_chained_list(t_env *env)
{
    t_token *iter;
    
    iter = env->first_token; 
    printf("==== LIST ====\n");
    while (iter)
    {
        print_token(iter);
        iter = iter->next;
    }
    printf("==== ==== ====\n");
}

void print_token(t_token *token)
{
    if (is_token_boolean(token))
    {
       printf("[%d][%s] : [%s]\n", token->index, convert_id(token->id), ((t_boolean *)token->class)->content);
       printf("    [IN][%s]\n", ((t_boolean *)token->class)->first); 
       printf("    [OUT][%s]\n\n", ((t_boolean *)token->class)->second);
    }
    else if (is_token_redirection(token))
    {
        print_redirection(token, get_class(token));
    }
    else if (is_token_cmd(token))
    {
        print_cmd(get_class(token), token->index);
    }
    else if (is_token_file(token))
    {
        printf("[%d][%s] : [%s]\n", token->index, convert_id(token->id), get_file_name(token));
        printf("   [FD : %d]\n\n", get_file_fd(token));
    }
    else
        printf("[%d][%s] : [%s]\n\n", token->index, convert_id(token->id), get_content(token));
}