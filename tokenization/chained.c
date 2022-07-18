/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:44:58 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/18 16:38:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void add_chained_list(t_env *env, t_token *token)
{
    t_token *iter;
    
    if (!(env->first_token))
        env->first_token = token;
    else 
    {
        iter = env->first_token;
        while (iter->next)
            iter = iter->next;
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