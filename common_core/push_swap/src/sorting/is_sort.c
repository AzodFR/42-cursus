/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:36:44 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 18:56:59 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sort(t_struct *ps)
{
	t_list *tmp;

	tmp = *(ps->lst_a);
	if (lst_size(ps->lst_b))
		return (0);
	while (tmp->next)
	{
		if ((long)tmp->content > (long)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
