/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:32:18 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/05 22:37:04 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_lst		*push_front(void *data, t_lst **lst)
{
	t_lst 	*elem;

	if (!lst)
		return (NULL);
	if (!(elem = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	elem->data = data;
	elem->next = *lst;
	*lst = elem;
	return *lst;
}

int		lstlen(t_lst *lst)
{
	t_lst		*tmp;
	uint32_t	index;

	index = 0;
	tmp = lst;
	while (tmp && ++index)
		tmp = tmp->next;
	return (index);
}

/*
** t_tab	*lst_to_tab(t_lst *lst, char *name, int size)
** {
** 	t_lst	*tmp;
** 	t_tab	*tab;
** 	int		i;
** 	int		len;
** 
** 	len = lstlen(lst);
** 	if (!(tab = (t_tab *)malloc(sizeof(t_tab))) && 
** 			!(tab->tab = (void *)malloc(sizeof(size) * len)))
** 		return (NULL);
** 	tab->len = len;
** 	tab->name = name;
** 	tmp = lst;
** 	i = -1;
** 	while (tmp)
** 	{
** 		tab->tab[++i] = tmp->data;
** 		lst = tmp;
** 		tmp = tmp->next;
** 		free(lst);
** 	}
** 	return (tab);
** }
*/
