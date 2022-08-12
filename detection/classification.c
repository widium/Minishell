/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:30:40 by ebennace          #+#    #+#             */
/*   Updated: 2022/08/12 14:07:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int redirection_classification(t_env *env, char *line, int index)
{
    t_token *token;
    int new_index;
    int type;
    char *content;

    new_index = redirection_detection(line, index);
    token = create_token_redir(line, index, new_index);
    add_chained_list(env, token);
    index = new_index;
    if (is_token_heredoc(token))
    {
        index = recover_limiter(get_class(token), line, ++index);
    }
    else if (is_token_basic_redirection(token))
    {
        index = next_file_tokenization(env, line, ++index);
    }
    return (index);
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
        token = command_classification(env, content);
        if (line_is_not_finish(line, new_index + 1))
            new_index = argument_detection(get_class(token), line, ++new_index);
    }
    else
    {
        token = tokenizer_word(content, TOKEN_WORD);
    }
    add_chained_list(env, token);
    return (new_index);
}

t_token *command_classification(t_env *env, char *content)
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