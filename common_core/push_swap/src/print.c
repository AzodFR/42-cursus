/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:13:20 by azod              #+#    #+#             */
/*   Updated: 2021/03/25 18:31:41 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void print_one(t_list **elem, long start, long end)
{
	int size;
	long n;

	size = 0;
	n = 0;
	if (*elem)
		n = (long)(*elem)->content;
	if (*elem && n >= start && n < end)
		size = printf("\e[92m%ld", (long)(*elem)->content) - 5;
	else if (*elem)
		size = printf("%ld", (long)(*elem)->content);
	printf("%*s", 21 - size, " ");
	if (*elem)
		(*elem) = (*elem)->next;
}

void print_stack(t_struct *ps, char *last, int i)
{
	t_list *tmp;
	t_list *tmp2;

	if (ps->debug)
	{
		usleep(SPEED * 100000);
		tmp = *(ps->lst_a);
		tmp2 = *(ps->lst_b);
		printf("\x1b[2J _____________________ _____________________\n");
		printf("|\e[92m%-21s\e[0m|\e[93m%21s\e[0m|\n", "STACK", "TMP");
		printf("|_____________________|_____________________|\n");
		while (++i < ps->size)
		{
			printf("|");
			print_one(&tmp, ps->start, ps->end);
			printf("\e[0m|");
			print_one(&tmp2, ps->start, ps->end);
			printf("\e[0m|\n");
		}
		printf("|_____________________ _____________________|\n");
	}
	if (ps->color)
		printf("\e[95m%s\e[0m\n", last);
	else
		printf("%s\n", last);
}
