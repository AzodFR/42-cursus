/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 07:08:41 by azod              #+#    #+#             */
/*   Updated: 2021/03/29 07:09:25 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long get_middle(t_list **lst)
{
	long total;
	t_list *tmp;
	int size;

	size = lst_size(lst);
	if (!size)
		return (0);
	tmp = *lst;
	total = 0;
	while (tmp)
	{
		total += (long)tmp->content;
		tmp = tmp->next;
	}
	return ((long)(total / size + 0.5));
}

t_list *get_at_pos(t_list **lst, int n)
{
	int i;
	t_list *tmp;

	i = -1;
	tmp = *lst;
	while (tmp && ++i < n)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	return (NULL);
}

int get_pos(t_list **lst, long n)
{
	t_list *tmp;
	int i;

	tmp = *lst;
	i = 0;
	while (tmp)
	{
		if ((long)tmp->content == n)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
