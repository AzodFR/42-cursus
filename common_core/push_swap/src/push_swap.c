/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:55 by azod              #+#    #+#             */
/*   Updated: 2021/03/26 10:35:30 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int define_chunk(int size)
{
	if (size <= 10)
		return (5);
	if (size >= 10 && size <= 50)
		return (10);
	if ((size >= 50 && size <= 100) || size <= 50)
		return (17);
	if (size >= 100 && size <= 300)
		return (35);
	return (47);
}

int main(int ac, char **av)
{
	t_struct *ps;

	if (ac < 2)
		ft_exit("Error", 1);
	ps = wrmalloc(sizeof(t_struct));
	parse(av, ps, 0);
	if (is_sort(ps))
		ft_exit("", 0);
	else if (ps->size <= 5)
		mini_sort(ps);
	else
	{
		ps->min = sort_long_tab(ps, -1);
		ps->min[ps->size] = ps->min[ps->size - 1] + 1;
		ps->chunck = define_chunk(ps->size);
		ps->start = ps->min[0];
		ps->end = ps->min[ps->chunck];
		ps->push = ps->chunck;
		empty_chunk_a(ps);
		fill_sorted_a(ps);
	}
	if (!is_sort(ps))
		ft_exit("Error", 1);
	wrdestroy();
	return (0);
}
