/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:14:57 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/12 15:34:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void remove_all_token(t_env *env)
{
    t_token *token;
    t_token *iter;

    if (!(env->first_token))
        return;
    token = get_first_token(env);
    while (token)
    {
        iter = token->next;
        disconect_token(token);
        remove_token(token);
        token = iter;
    }
    env->first_token = NULL;
}

void disconect_token(t_token *token)
{
    token->next = NULL;
    token->prev = NULL; 
}

void remove_token(t_token *token)
{
    if (is_token_cmd(token))
    {
        remove_token_cmd(get_class(token));
    }
    else if (is_token_redirection(token))
    {
        remove_token_redir(get_class(token)); 
    }
    else if (is_token_boolean(token))
    {
        remove_token_bool(get_class(token));
    }
    else if (is_token_file(token))
    {
        remove_token_file(get_class(token));
    }
    free(token);
    
}

// void	free_array_2(char **array)
// {
// 	int	i;
// 	if (!(array))
// 		return;
// 	i = 0;
// 	while (array[i])
// 	{
//         // printf("[%s : %p]\n", array[i+1], array[i+1]);
// 		free(array[i]);
// 		array[i] = NULL;
// 		i++;
// 	}
// 	free(array);
// }

void remove_token_cmd(t_cmd *cmd)
{
    // printf("[%s] \n", cmd->content);
    if (cmd->bin)
        free(cmd->bin);
    cmd->bin = NULL;
    if (cmd->arg)
        free(cmd->arg);
    cmd->arg = NULL;
    if (cmd->args)
    {
        print_array_fd(cmd->args, 2);
        free_array(cmd->args);  
        cmd->args = NULL;
    }
    if (cmd->content)
        free(cmd->content);
    cmd->content = NULL;
    remove_all_arg(cmd);
    if (cmd)
        free(cmd);
    cmd = NULL;
    
}

void remove_token_redir(t_redirection *redir)
{
    free(redir->content);
    free(redir->limiter);
    free(redir);
}

void remove_token_bool(t_boolean *boolean)
{
    free(boolean->content);
    free(boolean->first);
    free(boolean->second);
    free(boolean);
}

void remove_token_file(t_file *file)
{
    free(file);
}