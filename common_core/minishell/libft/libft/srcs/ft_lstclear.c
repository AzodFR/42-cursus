/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:42:35 by azod              #+#    #+#             */
/*   Updated: 2021/01/08 16:27:56 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *prev;

	if (!del)
		return;
	while (*lst)
	{
		del((*lst)->content);
		prev = *lst;
		*lst = (*lst)->next;
		wrfree(prev);
	}
	*lst = NULL;
}
