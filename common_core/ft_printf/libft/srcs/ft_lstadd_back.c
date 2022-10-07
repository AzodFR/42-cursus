/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:30:13 by azod              #+#    #+#             */
/*   Updated: 2020/11/26 10:04:37 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!new || !alst)
		return;
	else if ((*alst) == NULL)
		(*alst) = new;
	else
		ft_lstadd_back(&(*alst)->next, new);
}
