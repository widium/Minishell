/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:55:24 by ebennace          #+#    #+#             */
/*   Updated: 2022/07/20 13:52:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"

int main(int argc, char **argv, char **env)
{
    int fd = access("/bin/wc", R_OK & W_OK & X_OK & F_OK);
    printf("%d\n",fd);
}