/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 21:36:27 by azod              #+#    #+#             */
/*   Updated: 2021/01/08 16:24:58 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int i;
	char *newstr;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(newstr = wrmalloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i])
		newstr[i] = (*f)(i, s[i]);
	newstr[i] = 0;
	return (newstr);
}
