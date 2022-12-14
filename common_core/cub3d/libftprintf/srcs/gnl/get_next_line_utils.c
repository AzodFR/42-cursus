/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:07 by azod              #+#    #+#             */
/*   Updated: 2020/12/14 12:35:25 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strchrgnl(char *s, char c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}

int ft_strlengnl(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strcpygnl(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char *ft_strdupgnl(char *s)
{
	char *ptr;
	int i;

	i = -1;
	if (!(ptr = (char *)malloc((ft_strlengnl(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = 0;
	return (ptr);
}

char *ft_substring(char *str, unsigned int start, unsigned int len)
{
	unsigned int i;
	unsigned int j;
	unsigned int count;
	char *newstr;

	i = 0;
	j = ft_strlengnl(str);
	if (start >= j || j == 0)
		return (ft_strdupgnl(""));
	count = start - j;
	if (count > len)
		count = len;
	if (!(newstr = malloc((count + 1) * sizeof(char))))
		return (NULL);
	while (len--)
		newstr[i++] = str[start++];
	newstr[i] = 0;
	return (newstr);
}
