/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:10:09 by azod              #+#    #+#             */
/*   Updated: 2020/11/23 12:54:37 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *mamiemory;

	if (!(mamiemory = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(mamiemory, size * nmemb);
	return (mamiemory);
}
