/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:01:40 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 16:41:19 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **dest, t_list **src, t_struct *ps, int type)
{
	t_list *tmp;

	if (!lst_size(src))
		return;
	tmp = new_lst((*src)->content);
	(*src) = (*src)->next;
	lst_push_front(dest, tmp);
	if (type)
		print_stack(ps, "pa", -1);
	else
		print_stack(ps, "pb", -1);
}
