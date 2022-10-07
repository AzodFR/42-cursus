/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:04:20 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 16:41:08 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_list **lst, t_struct *ps, int aff, int type)
{
	t_list *tmp;

	if (lst_size(lst) < 2)
		return;
	tmp = *lst;
	*lst = tmp->next;
	tmp->next = NULL;
	lst_push_back(lst, tmp);
	if (aff)
	{
		if (type)
			print_stack(ps, "ra", -1);
		else
			print_stack(ps, "rb", -1);
	}
}

void reverse_rotate(t_list **lst, t_struct *ps, int aff, int type)
{
	t_list *tmp;
	t_list *tmp2;

	if (lst_size(lst) < 2)
		return;
	tmp = lst_get_last(lst);
	tmp2 = *lst;
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	lst_push_front(lst, tmp);
	if (aff)
	{
		if (type)
			print_stack(ps, "rra", -1);
		else
			print_stack(ps, "rrb", -1);
	}
}

void double_rotate(t_struct **ps, int aff)
{
	rotate((*ps)->lst_a, *ps, 0, 0);
	rotate((*ps)->lst_b, *ps, 0, 0);
	if (aff)
		print_stack(*ps, "rr", -1);
}

void double_rev_rotate(t_struct **ps, int aff)
{
	reverse_rotate((*ps)->lst_a, *ps, 0, 0);
	reverse_rotate((*ps)->lst_b, *ps, 0, 0);
	if (aff)
		print_stack(*ps, "rrr", -1);
}
