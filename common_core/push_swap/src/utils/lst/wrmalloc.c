/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrmalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:08:44 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 12:07:36 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static t_list **wrgetter(void)
{
	static t_list *wrm;

	return (&wrm);
}

void *wrmalloc(unsigned long size)
{
	char *buffer;
	t_list *new_elem;

	buffer = malloc(size);
	if (!buffer)
	{
		wrdestroy();
		printf("malloc error");
		exit(1);
	}
	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
	{
		free(buffer);
		wrdestroy();
		printf("malloc error");
		exit(1);
	}
	new_elem->content = buffer;
	new_elem->next = 0;
	lst_push_back(wrgetter(), new_elem);
	return (buffer);
}

int wrfree(void *ptr)
{
	t_list *prev;
	t_list *current;
	t_list *next;
	t_list **wrstart;

	prev = 0;
	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		if (current->content == ptr)
		{
			free(ptr);
			free(current);
			if (prev)
				prev->next = next;
			else
				*wrstart = next;
			return (EXIT_SUCCESS);
		}
		prev = current;
		current = current->next;
	}
	return (EXIT_FAILURE);
}

void wrdestroy(void)
{
	t_list *current;
	t_list *next;
	t_list **wrstart;

	wrstart = wrgetter();
	current = *wrstart;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	*wrstart = 0;
}
