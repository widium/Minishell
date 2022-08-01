/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:50:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/01 15:59:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

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

void print_cmd(t_cmd *cmd, int index)
{
    printf("[%d][%s] : [%s]\n", index, convert_id(cmd->id), cmd->content);
    if (have_args(cmd))
        print_args(cmd);
    else
        print_array(cmd->args);
}

void print_args(t_cmd *cmd)
{
    t_arg *iter;
    int i;

    i = 1;
    iter = cmd->first_arg;
    if (!iter)
        return;
    while (iter)
    {
        printf("   [%d][%s] : [%s]\n", i, convert_id(iter->id), iter->content);
        i++;
        iter = iter->next;
    }
    printf("\n");
}

void print_redirection(t_token *token, t_redirection *redir)
{
    printf("[%d][%s] : [%s]\n", token->index, convert_id(redir->type), redir->content);
    if (redir->type == TOKEN_HERE_DOC)
    {
        printf("    [%s][%s]\n", convert_id(TOKEN_LIMITER), redir->limiter);
    }
    else 
    {
       printf("   [FD_IN : %d]\n", redir->fd_in);
       printf("   [FD_OUT : %d]\n", redir->fd_out);
    }
    printf("\n");
}

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
    //print_token(iter);
    printf("==== ==== ====\n");
}

void print_detection(char *line, int start, int end, int token)
{
    printf("DETECTION : [");
    while (line[start] && start <= end)
    {
        printf("%c", line[start]);
        start++;
    }
    printf("]\n");
    
}

void print_array(char **str)
{
    int i;

    if (!str)
        return;
    i = 0;
    while(str)
    {
        printf("%s\n", str[i]);
        i++;
    }
}

void print_str_index(char *str, int i)
{
    while (str[i])
    {
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}


char *convert_id(int id)
{
    if (id == TOKEN_NULL)
        return ("TOKEN_NULL");
    if (id == TOKEN_BLANK)
        return ("TOKEN_BLANK");
    if (id == TOKEN_WORD)
        return ("TOKEN_WORD");
    if (id == TOKEN_SINGLE_QUOTE)
        return ("TOKEN_SINGLE_QUOTE");
    if (id == TOKEN_DOUBLE_QUOTE)
        return ("TOKEN_DOUBLE_QUOTE");
    if (id == TOKEN_PARANTHESIS)
        return ("TOKEN_PARANTHESIS");
    if (id == TOKEN_REDIRECTION)
        return ("TOKEN_REDIRECTION");
    if (id == TOKEN_COMMAND)
        return ("TOKEN_COMMAND");
    if (id == TOKEN_BUILT_IN)
        return ("TOKEN_BUILT_IN");
    if (id == TOKEN_BINARY)
        return ("TOKEN_BINARY");
    if (id == TOKEN_FLAGS)
        return ("TOKEN_FLAGS");
    if (id == TOKEN_ARGUMENT)
        return ("TOKEN_ARGUMENT");
    if (id == TOKEN_VARIABLE)
        return ("TOKEN_VARIABLE");
    if (id == TOKEN_FILE)
        return ("TOKEN_FILE");
    if (id == TOKEN_AND)
        return ("TOKEN_AND");
    if (id == TOKEN_OR)
        return ("TOKEN_OR");
    if (id == TOKEN_WILDCARD)
        return ("TOKEN_WILDCARD");
    if (id == TOKEN_PIPE)
        return ("TOKEN_PIPE");
    if (id == TOKEN_INPUT_CHEVRON)
        return ("TOKEN_INPUT_CHEVRON");
    if (id == TOKEN_OUTPUT_CHEVRON)
        return ("TOKEN_OUTPUT_CHEVRON");
    if (id == TOKEN_APPEND_CHEVRON)
        return ("TOKEN_APPEND_CHEVRON");
    if (id == TOKEN_HERE_DOC)
        return ("TOKEN_HERE_DOC");
    if (id == TOKEN_BOOLEAN)
        return ("TOKEN_BOOLEAN"); 
    if (id == TOKEN_LIMITER)
        return ("TOKEN_LIMITER");
    if (id == TOKEN_STRING)
        return ("TOKEN_STRING");
    return ("NULL");
}

