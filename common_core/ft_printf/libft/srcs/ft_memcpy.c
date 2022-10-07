/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:37:35 by azod              #+#    #+#             */
/*   Updated: 2020/11/23 11:26:37 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;
	unsigned char *dst;
	unsigned const char *source;

	if (!dest && !src && n)
		return (NULL);
	dst = (unsigned char *)dest;
	source = (unsigned const char *)src;
	i = -1;
	while (++i < n)
		dst[i] = source[i];
	return (dest);
}
