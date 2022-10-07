/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:33:00 by azod              #+#    #+#             */
/*   Updated: 2020/11/23 11:27:09 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!(dest) && !(src))
		return (NULL);
	if ((unsigned char *)dest < (const unsigned char *)src)
		while (n--)
		{
			((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	else
		while (n--)
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	return (dest);
}
