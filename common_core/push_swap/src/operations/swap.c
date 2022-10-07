/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:56:00 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 16:40:40 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **lst, t_struct *ps, int aff, int type)
{
	t_list *tmp;

	if (lst_size(lst) < 2)
		return;
	tmp = *lst;
	tmp = tmp->next;
	(*lst)->next = tmp->next;
	tmp->next = (*lst);
	*lst = tmp;
	if (aff)
	{
		if (type)
			print_stack(ps, "sa", -1);
		else
			print_stack(ps, "sb", -1);
	}
}

void double_swap(t_struct **ps, int aff)
{
	swap((*ps)->lst_a, *ps, 0, 0);
	swap((*ps)->lst_b, *ps, 0, 0);
	if (aff)
		print_stack(*ps, "ss", -1);
}
