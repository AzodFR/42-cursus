/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:51:44 by azod              #+#    #+#             */
/*   Updated: 2020/11/23 11:26:19 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *src;

	i = -1;
	src = (unsigned char *)s;
	while (++i < n)
		if (src[i] == (unsigned char)c)
			return (&src[i]);
	return (NULL);
}
