/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose_class.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:21:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/09/25 15:22:22 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"




void print_all_env_var(t_env * env)
{
    t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        if (var->id == VALUE)
            print_env_var(var);
        var = var->next;
    }
}

void print_all_env_export_var(t_env * env)
{
    t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        print_env_var(var);
        var = var->next;
    }
}

void print_env_var(t_env_var *var)
{
    if (!var || !var->name)
        return ;
    if (!var->value)
        ft_printf("%s\n", var->name);
    else
	    ft_printf("%s=%s\n", var->name, var->value);
}

void print_all_env_var_struct(t_env * env)
{
    t_env_var *var;

    var = get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        print_env_var_struct(var);
        var = var->next;
    }
}

void print_env_var_struct(t_env_var *var)
{
	printf(" ---[%s]---\n", var->name);
    printf(" | type : [%d]\n", var->id);
	printf(" | index : [%d]\n", var->index);
    printf(" | value : [%s]\n", var->value);
    printf(" ----------------\n");
}

void print_cmd(t_cmd *cmd, int index)
{
    printf("[%d][%s] : [%s]\n", index, convert_id(cmd->id), cmd->content);
    if (cmd_have_args(cmd))
        print_args(cmd);
    else if (cmd_have_args_array(cmd))
        print_args_array(cmd->args);
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

void print_args_array(char **args)
{
    int i;

    if (!args)
        return;
    i = 0;
    printf("   [ARGS][");
    while(args[i])
    {
        printf("%s", args[i]);
        i++;
    }
    printf("]\n");
}

void print_redirection(t_token *token, t_redir *redir)
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