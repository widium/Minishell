/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:50:04 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/19 18:34:51 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void print_token(t_token *token)
{
    if (token->id == TOKEN_BOOLEAN)
    {
       printf("[%d][%s] : [%s] --> {in [%s] : out [%s]}\n", token->index, 
        convert_id(token->id), ((t_boolean *)token->class)->content, ((t_boolean *)token->class)->first, ((t_boolean *)token->class)->second); 
    }
    else if (token->id == TOKEN_REDIRECTION)
    {
        printf("[%d][%s] : [%s] -> fd_in[%d] fd_out[%d]\n", token->index, 
        convert_id( ((t_redirection *)token->class)->type), ((t_redirection *)token->class)->content,
         ((t_redirection *)token->class)->fd_in, ((t_redirection *)token->class)->fd_out); 
    }
    else if (token->id == TOKEN_VARIABLE)
    {
        printf("[%d][%s] : [%s]\n", token->index, convert_id(TOKEN_VARIABLE),
        ((t_variable *)token->class)->content);
    }
    else if (token->id == TOKEN_BUILT_IN)
    {
        printf("[%d][%s] : [%s]\n   [%s]: [%s]\n   [%s]: [%s]\n", token->index, convert_id(TOKEN_BUILT_IN),
        ((t_cmd *)token->class)->content, 
        "FLAGS",((t_cmd *)token->class)->flags, 
        "ARGUMENT",((t_cmd *)token->class)->arg);
    }
    else
        printf("[%d][%s] : [%s]\n", token->index, convert_id(token->id), get_content(token));
}

void print_chained_list(t_env *env)
{
    t_token *iter;
    
    iter = env->first_token; 
    printf("==== LIST ====\n");
    while (iter->next)
    {
        print_token(iter);
        iter = iter->next;
    }
    print_token(iter);
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
    return ("NULL");
}

