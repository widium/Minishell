/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:11:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 18:01:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"



char *get_env_var_value_with_name(t_env *  env, char *name)
{
   t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return (NULL);
    while (var)
    {
        if (same_name(var->name, name))
        {
            return (var->value);
        }
        var = var->next;
    }
    return (NULL); 
}

t_env_var *get_env_var_with_name(t_env *  env, char *name)
{
    t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return (NULL);
    while (var)
    {
        if (same_name(name, var->name))
        {
            return (var);
        }
        var = var->next;
    }
    return (0);
}

t_env_var *get_first_env_var(t_env * env)
{
    if (env->first_var)
        return (env->first_var);
    return (0);
}

t_env_var *get_last_env_var(t_env *  env)
{
    t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return (NULL);
    while (var)
    {
        if (!var->next)
            return (var);
        var = var->next;
    }
    return (0);
}

int get_env_var_size(t_env *  env)
{
    t_env_var *var;
    int i;

    var = get_first_env_var(env);
    if (!var)
        return (0);
    i = 0;
    while (var)
    {
        i++;
        var = var->next;
    }
    return (i);
}

t_line *get_first_line(t_env *env)
{
    if (env->first_line)
        return (env->first_line);
    return (0);
}

t_arg *get_first_arg(t_cmd *cmd)
{
    if (cmd->first_arg)
        return (cmd->first_arg);
    return (0);
}

t_token *get_first_token(t_env *env)
{   
    if (env->first_token)
        return (env->first_token);
    return (0);
}

t_cmd *get_first_cmd(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_token *get_next_token_cmd(t_token *token)
{
    token = token->next;
    while (token)
    {
        if (is_token_cmd(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_token *get_next_token_built_in(t_token *token)
{
    token = token->next;
    while (token)
    {
        if (is_token_built_in(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_redir *get_first_redirection(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_token *get_first_token_cmd(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_cmd(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_token *get_first_token_built_in(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_built_in(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_token *get_first_token_redirection(t_env *env)
{
    t_token *token;

    if (!(get_first_token(env)))
        return (NULL);
    token = get_first_token(env);
    while (token)
    {
        if (is_token_redirection(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

t_token *get_next_token_redirection(t_token *token)
{
    token = token->next;
    while (token)
    {
        if (is_token_redirection(token))
            return (token);
        token = token->next;
    }
    return (NULL);
}

int get_nbr_pipes(t_env *env)
{
    t_token *token;
    int count;

    if (!(get_first_token(env)))
        return (0);
    count = 0;
    token = get_first_token(env);
    while (token)
    {
        if (is_token_pipe(token))
            count++;
        token = token->next;
    }
    return (count);
}

t_cmd *get_prev_cmd(t_token *token)
{ 
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->prev;
    }
    return (NULL);
}

t_cmd *get_next_cmd(t_token *token)
{   
    while (token)
    {
        if (is_token_cmd(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

t_file *get_next_file(t_token *token)
{   
    while (token)
    {
        if (is_token_file(token))
            return (get_class(token));
        token = token->next;
    }
    return (NULL);
}

char *get_cmd_path(t_cmd *cmd)
{
    if (cmd->bin)
        return (cmd->bin);
    return (NULL);
}

char **get_cmd_args(t_cmd *cmd)
{
    if (cmd->args)
        return (cmd->args);
    return (NULL);
}

char **get_env_variables(t_env *env)
{
    char **env_var;

    env_var = env_var_list_to_array(env);
    return (env_var);
}

char **get_env_bins(t_env *env)
{
    t_env_var *var;
    char *path;
    char **bins;

    path = get_env_var_value_with_name(env, "PATH");
    if (!path)
        return (NULL);
    bins = ft_split(path, ':');
    return (bins);
}

int get_number_args(t_cmd *cmd)
{
    int nb;
    t_arg *arg;

    if (!(cmd_have_args(cmd)))
        return (0);
    arg = get_first_arg(cmd);
    nb = 0;
    while (arg)
    {
        nb++;
        arg = arg->next;
        
    }
    return (nb);
}

char *get_home_path(t_env *env)
{
    char *value;

    value = get_env_var_value_with_name(env, "HOME");
    return (value);
}

char *get_current_path(void)
{
    char *path;
    
    path = getcwd(NULL, 0);
    if (path == NULL)
        perror("getcwd() Error\n");
    return (path);
}

char *get_parent_path(t_env *env)
{
    char *current_path;
    char *parent_path;
    int index;
    
    current_path = get_current_path();
    index = return_last_back_slash_index(current_path);
    parent_path = malloc_strcpy_index(current_path, index);
    free(current_path);
    return (parent_path);
}

char *get_last_path(t_env *env)
{
    char *last_path;
    char *path;
    
    last_path = get_env_var_value_with_name(env, "PWD");
    path = malloc_strcpy(last_path);
    return (path);
}