/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:17:32 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 18:26:57 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void redirection(t_env *env)
{
    t_token *token;
    t_cmd *prev_cmd;
    t_cmd *next_cmd;
    t_file *next_file;
    int pipes;

    if (have_token_redirection(env))
    {
        token = get_first_token_redirection(env);
        while (token)
        {
            create_fd_for_redirection(token);
            token = get_next_token_redirection(env, token);
        }
    }
    else
        return ;   
}

void create_fd_for_redirection(t_token *token)
{
    t_cmd *prev_cmd;
    t_cmd *next_cmd;
    t_file *next_file;
    
    if (is_token_simple_redirection(token))
    {
        prev_cmd = get_prev_cmd(token);
        next_cmd = get_next_cmd(token);
        next_file = get_next_file(token);
        
        if (is_token_input_chevron(token))
        {
            open_file_with_good_flags(token, next_file);
            change_fd_cmd(prev_cmd, next_file->fd, prev_cmd->fd_out);
        }
        else if (is_token_output_chevron(token))
        {
            open_file_with_good_flags(token, next_file);
            change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
        }
        else if (is_token_append_chevron(token))
        {
            open_file_with_good_flags(token, next_file);
            change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
        }
    }
    else if (is_token_pipe(token))
    {
        printf("redirect pipes\n");
    }
    else if (is_token_heredoc(token))
    {
        printf("redirect heredoc\n");
    }
}

void open_file_with_good_flags(t_token *token, t_file *file)
{
    if (is_token_input_chevron(token))
    {
        close(file->fd);
        file->fd = open(file->name, O_RDONLY);
    }
    else if (is_token_output_chevron(token))
    {
        close(file->fd);
        file->fd = open(file->name, O_WRONLY | O_TRUNC);
    }
    else if (is_token_append_chevron(token))
    {
        close(file->fd);
        file->fd = open(file->name, O_WRONLY | O_APPEND);
    }
}

void change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out)
{
    cmd->fd_in = fd_in;
    cmd->fd_out = fd_out;
}

int have_token_redirection(t_env *env)
{
    t_token *token;

    if (!(have_token(env)))
        return (0);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (1);
        token = token->next;
    }
    return (0); 
}