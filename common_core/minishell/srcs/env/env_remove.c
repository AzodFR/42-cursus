/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:51:49 by azod              #+#    #+#             */
/*   Updated: 2021/02/11 15:45:38 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mishell.h"

static void ft_remove_elem(t_env **ptr_back, t_env **ptr)
{
	(*ptr_back)->next = (*ptr)->next;
	wrfree((*ptr)->name);
	wrfree((*ptr)->value);
	wrfree(*ptr);
	*ptr = (*ptr_back)->next;
}

void ft_env_remove_if(t_env **begin_list, void *name_ref, int (*cmp)())
{
	t_env *ptr;
	t_env *ptr_back;

	if (*begin_list == NULL)
		return;
	ptr = (*begin_list)->next;
	ptr_back = (*begin_list);
	while (ptr)
	{
		if (cmp(ptr->name, name_ref) == 0)
			ft_remove_elem(&ptr_back, &ptr);
		else
		{
			ptr_back = ptr;
			ptr = ptr->next;
		}
	}
	if (cmp((*begin_list)->name, name_ref) == 0)
	{
		ptr = (*begin_list)->next;
		wrfree((*begin_list)->name);
		wrfree(ptr->value);
		wrfree(*begin_list);
		*begin_list = ptr;
	}
}
