/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlnode	*dllst_findstr(t_lst *list, const char *str, t_byte head)
{
	t_dlnode	*tmp;

	if (!list || !list->len || !str)
		return (0);
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		if (!ft_strncmp(tmp->data, str, ft_strlen(str)))
			return (tmp);
		tmp = head ? tmp->next : tmp->prev;
	}
	return (0);
}

void		dllst_delstr(t_lst *list, const char *str, t_byte head)
{
	t_dlnode	*del;

	if (!list || !list->len || !str)
		return ;
	del = dllst_findstr(list, str, head);
	if (!del)
		return ;
	if (del->prev)
		del->prev->next = del->next;
	if (del->next)
		del->next->prev = del->prev;
	dlnode_free(&del);
}

void		dllst_print(t_lst *list, t_byte head)
{
	t_dlnode	*tmp;

	if (!list || !list->len)
		return ;
	tmp = head ? list->head : list->tail;
	while (tmp)
	{
		ft_putendl(tmp->data);
		tmp = head ? tmp->next : tmp->prev;
	}
}

void		dllst_del(t_lst *list)
{
	t_dlnode	*head;

	if (!list)
		return ;
	head = list->head;
	if (head)
		dlinklst_free(&head);
	list->head = 0;
	list->tail = 0;
	list->len = 0;
}
