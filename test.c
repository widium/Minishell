/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:55:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/05 17:30:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

int is_append_redirection(char *str, int i)
{
    while (str[i++])
        printf("%c", str[i]);
}


int main()
{
    int i = 0;
    char *str = " echo salut moi c'est eddie | wc -l";
    while (str[i])
    {
        if (i > 8)
            break;
        i++;
    }
    is_append_redirection(str, i);
}
