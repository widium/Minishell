/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:42:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/23 15:27:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

void parsing(t_env *env, char *line)
{
    int index;
    int type;
    int new_index;
    int count;
    t_token *token;
    char *content;

    count = 0;
    index = 0;
    new_index = index;
    
    while (line[index])
    {
        if (is_word(line, index))
        { 
            index = word_classification(env, line, index);
        }
        else if (is_redirection(line, index))
        {
            index = redirection_classification(env, line, index);
        }
        if (is_boolean_operator(line, index))
        {
            new_index = boolean_detection(line, index);
            token = tokenizer_bool(line, index, new_index, TOKEN_BOOLEAN);
            add_chained_list(env, token);

            index = new_index;
        }
        index++;
    }
    print_chained_list(env);
    
     
}

// if (is_paranthesis(line, index))
        // {
        //     new_index = paranthesis_detection(line, index);
        //     token = tokenizer(line, index, new_index, TOKEN_PARANTHESIS);
        //     add_chained_list(env, token);

        //     index = new_index;
        // }
 
int redirection_classification(t_env *env, char *line, int index)
{
    t_token *token;
    int new_index;
    int type;
    char *content;
    
    new_index = redirection_detection(line, index);
    content = ft_substr(line, index, (new_index - index) + 1);
    type = type_of_redirect(content);
    if (type == TOKEN_HERE_DOC)
    {
        token = create_token_redir(type, content);
        new_index = recover_limiter((t_redirection *)token->class, line, ++new_index);
    }
    else
        token = create_token_redir(type, content);

    add_chained_list(env, token);
    return (new_index);
}

int word_classification(t_env *env, char *line, int index)
{
    char *content;
    int new_index;
    t_token *token;
    
    new_index = word_detection(line, index);
    content = ft_substr(line, index, (new_index - index) + 1);
    if (is_cmd(content))
    {
        token = command_classification(content, line, index);
        new_index = argument_detection((t_cmd *)token->class, line, ++new_index);
    }
    else if (is_file(line, index))
        token = tokenizer_file(content, TOKEN_FILE);
    else
        token = tokenizer(line, index, new_index, TOKEN_WORD);
    add_chained_list(env, token);
    return (new_index);
}

t_token *command_classification(char *content, char *line, int index)
{
    t_token *token;

    if (is_built_in(content))
    {
        token = tokenizer_command(content, TOKEN_BUILT_IN);
    }   
    else if (is_bin(content))
    {
        token = tokenizer_command(content, TOKEN_BINARY);
    }
    return (token);
}