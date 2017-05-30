/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rromero <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 02:09:07 by rromero           #+#    #+#             */
/*   Updated: 2017/03/24 18:43:20 by rromero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_addstr(t_lst *list, const char *str)
{
	t_node		*add;

	if (!str)
		return ;
	if (!list->head)
	{
		list->head = ft_lstnew(str, ft_strlen(str) + 1);
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(str, ft_strlen(str) + 1);
		((t_node *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addnewarray(t_lst *list, const char *name)
{
	t_array		string;
	t_node		*add;

	if (!name)
		return ;
	string.data = ft_strdup(name);
	string.d_size = 1;
	string.len = ft_strlen(name);
	string.bytes = (string.len + 1);
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_node *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addwstr(t_lst *list, const wchar_t *name)
{
	t_array		string;
	t_node		*add;

	if (!name || !list)
		return ;
	string.data = wstrdup(name);
	string.d_size = sizeof(wchar_t);
	string.len = wstrlen(name);
	string.bytes = ((string.d_size * string.len) + sizeof(wchar_t));
	if (!list->head)
	{
		list->head = ft_lstnew(&string, sizeof(t_array));
		list->tail = list->head;
	}
	else
	{
		add = ft_lstnew(&string, sizeof(t_array));
		((t_node *)(list->tail))->next = add;
		list->tail = add;
	}
	list->len++;
}

void	lst_addarray(t_lst *list, t_array *add)
{
	t_node	*new;

	if (!add || !list)
		return ;
	new = ft_memalloc(sizeof(t_node));
	if (!new)
		return ;
	new->data = add;
	if (!list->head)
	{
		list->head = new;
		list->tail = list->head;
	}
	else
	{
		((t_node *)(list->tail))->next = new;
		list->tail = new;
	}
	list->len++;
}

void	dllst_addstr(t_lst *lst, const char *str)
{
	t_dlnode	*add;
	t_dlnode	*tmp;

	if (!str)
		return ;
	if (!lst->head)
	{
		lst->head = dlnode_new(str, ft_strlen(str) + 1);
		lst->tail = lst->head;
	}
	else
	{
		tmp = lst->tail;
		add = dlnode_new(str, ft_strlen(str) + 1);
		dlnode_addnext(tmp, add);
		lst->tail = add;
	}
	lst->len++;
}
