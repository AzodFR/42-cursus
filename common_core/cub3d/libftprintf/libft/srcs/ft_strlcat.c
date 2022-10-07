/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:08:27 by azod              #+#    #+#             */
/*   Updated: 2020/11/23 12:50:28 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, char *src, size_t size)
{
	size_t dstsize;
	size_t i;

	dstsize = 0;
	i = 0;
	while (dst[dstsize] && dstsize < size)
		dstsize++;
	while (src[i] && i + dstsize + 1 < size)
	{
		dst[dstsize + i] = src[i];
		i++;
	}
	if (dstsize != size)
		dst[dstsize + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (dstsize + i);
}
