/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:30:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/08 12:13:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// int redirection_classification(t_env *env, char *line, int index)
// {
//     t_token *token;
//     int new_index;
//     int type;
//     char *content;

//     new_index = redirection_detection(line, index);
//     content = malloc_substrcpy(line, index, (new_index - index) + 1);
//     type = type_of_redirect(content);
//     if (type == TOKEN_HERE_DOC)
//     {
//         token = create_token_redir(type, content);
//         new_index = recover_limiter(get_class(token), line, ++new_index);
//     }
//     else //if(type == TOKEN_PIPE)
//     {
//         token = create_token_redir(type, content);
//     }  
//     add_chained_list(env, token);
//     return (new_index);
//     // else
//     // {
//     //    token = create_token_redir(type, content);
//     //    add_chained_list(env, token);
       
//     //    new_index = file_detection(line, index);
//     //    content = malloc_substrcpy(line, index, (new_index - index) + 1);
//     //    token = tokenizer_file(content, TOKEN_FILE);
//     // }

// }

int redirection_classification(t_env *env, char *line, int index)
{
    t_token *token;
    int new_index;
    int type;
    char *content;

    new_index = redirection_detection(line, index);
    content = malloc_substrcpy(line, index, (new_index - index) + 1);
    index = new_index;
    
    type = type_of_redirect(content);
    
    if (type == TOKEN_HERE_DOC)
    {
        token = create_token_redir(type, content);
        index = recover_limiter(get_class(token), line, ++index);
    }
    else if (type == TOKEN_PIPE)
    {
       token = create_token_redir(type, content);
    }
    else
    {
        token = create_token_redir(type, content);
        add_chained_list(env, token);

        // index = next_file_detection(line, ++index);
        new_index = file_detection(line, ++index);
        content = malloc_substrcpy(line, index, (new_index - index) + 1);
        token = tokenizer_file(content, TOKEN_FILE);
        index = new_index;
    }
    add_chained_list(env, token);
    return (index);
}

int next_file_detection(char *line, int index)
{
    int new_index;
    char *content;
    t_token *token;
    
    
    return (new_index);
}
int word_classification(t_env *env, char *line, int index)
{
    char *content;
    int new_index;
    t_token *token;

    new_index = word_detection(line, index);
    content = malloc_substrcpy(line, index, (new_index - index) + 1);
    if (is_cmd(env, content))
    {
        token = command_classification(env, content, line, index);
        new_index = argument_detection(get_class(token), line, ++new_index);
    }
    else
    {
        token = tokenizer_word(content, TOKEN_WORD);
    }
    add_chained_list(env, token);
    return (new_index);
}

    // else if (is_file(line, index))
    // {
    //     token = tokenizer_file(content, TOKEN_FILE);
    // }

t_token *command_classification(t_env *env, char *content, char *line, int index)
{
    t_token *token;

    if (is_built_in(content))
    {
        token = tokenizer_command(content, TOKEN_BUILT_IN);
    }
    else if (is_bin(env, content))
    {
        token = tokenizer_command(content, TOKEN_BINARY);
    }
    return (token);
}

int boolean_classification(t_env *env, char *line, int index)
{
    t_token *token;
    int new_index;

    new_index = boolean_detection(line, index);
    token = tokenizer_bool(line, index, new_index, TOKEN_BOOLEAN);
    add_chained_list(env, token);
    return (new_index);
}