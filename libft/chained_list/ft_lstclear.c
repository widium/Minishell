/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:40:12 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:35:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*t_tmp;

	if (!(lst) || !(del))
		return ;
	tmp = *lst;
	while (tmp)
	{
		t_tmp = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = t_tmp;
	}
	*lst = NULL;
}

/* Declaration de 2 variables temporaire
 * Verifier Le contenue de la fonctions et de la liste
 * Tant que temporaire n'est pas egale a NULL
 * on passe a la prochaine list que l'on assigne dans une autre variables
 * temporaire
 * On free cette elements
 * Et on remet t_tmp dans tmp pour pouvoir itereter entres les elements
 *
 * Le but de cette fonctions et d'iterer dans une liste chainer et de supprimer
 * chaque elements , un par un avec l'aide de variables temporaire.
 * et la fin on retourne une tete de liste NULL ==> ce qui equivaut
 * a léntierter de la liste NULL
 */
