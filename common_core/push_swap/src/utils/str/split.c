/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod         <contact@azod.io>                 +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:16:44 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 16:38:38 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char *malloc_a_case(const char *str, char c)
{
	int i;
	char *buf;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	buf = wrmalloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != c && str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static int malloc_all(const char *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

char **ft_split(char const *s, char c)
{
	char **strs;
	int i;

	i = 0;
	if (!s)
		return (NULL);
	strs = wrmalloc(sizeof(char *) * (malloc_all(s, c) + 1));
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			strs[i] = malloc_a_case(s, c);
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	strs[i] = NULL;
	return (strs);
}
