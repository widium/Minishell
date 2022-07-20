/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/20 19:21:15 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void add_chained_list(t_env *env, t_token *token)
{
    t_token *iter;
    int i;
    
    i = 1;
    if (!(env->first_token))
    {
        env->first_token = token;
        token->index = i;
    } 
    else 
    {
        iter = env->first_token;
        i++;
        while (iter->next)
        {
            i++;
            iter = iter->next;  
        }
        token->index = i; 
        connect_token(iter, token);
    }
}

t_token *word_classfication(char *line, char *content, int index)
{
    t_token *token;
    
    if (is_built_in(content))
    {
        token = create_token(content, TOKEN_BUILT_IN);
        command_information(token, line, index);
    }  
    else
        token = create_token(content, TOKEN_WORD);
    return (token);
}