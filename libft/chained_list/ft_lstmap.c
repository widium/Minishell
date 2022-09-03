/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:11:43 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/20 13:35:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_content;
	t_list	*lst_final;

	if (!(lst))
		return (NULL);
	lst_final = 0;
	while (lst)
	{
		new_content = ft_lstnew(f(lst->content));
		if (!new_content)
		{
			ft_lstclear(&lst_final, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_final, new_content);
		lst = lst->next;
	}
	return (lst_final);
}

/* renvoie une list
 * prend en arguments :
 *	- une lst
 *	- un pointeur sur un pointeur de fonctions
 *	- un pointeur sur une fonctions (del)
 *
 * le but de cette fonctions est d'appliquer la fonctions (f) sur chaque
 * NOUVELLE elements de la liste chainer et que si ce nouvelle n'as pas eter
 * modifier on applique la fonctions del qui permet de le supprimer
 *
 * On declare 2 list_t :
 * - new_content pour creer un nouveuax contenue et de le modifier
 * - lst_final qui est l'adresse de la tete de liste a renvoyer
 *
 * On check si la lst est vide
 *
 * On itere dans chacun des elements de la lst
 *		on creer un nouveaux contenue avec la fonctions ft_newlst(le contenue
 *		de liste de base
 *
 *		si il n'ya rien dedant le nouveaux contenue on le supprime
 *
 *		On ajoute le nouveaux contenue a la suite de la lst_final
 *
 *		On incremente pour passer a la nouvelle list
 */
