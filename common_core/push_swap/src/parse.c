/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:04:50 by azod              #+#    #+#             */
/*   Updated: 2021/03/26 10:52:49 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_struct(t_struct *ps)
{
	ps->lst_a = wrmalloc(sizeof(t_list *));
	*ps->lst_a = NULL;
	ps->debug = 0;
	ps->color = 0;
	ps->flag = 0;
	ps->lst_b = wrmalloc(sizeof(t_list *));
	*ps->lst_b = NULL;
}

int is_valid(char *s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (i != 0 && (s[i] == '+' || s[i] == '-') && s[i - 1] != s[i])
			return (0);
		else if (is_alpha(s[i]))
			return (0);
		else if (!is_digit(s[i]) && i && s[i - 1] != s[i])
			return (0);
	}
	return (1);
}

int duplicate(t_list **lst, long n)
{
	t_list *tmp;

	tmp = (*lst);
	if (n > 2147483647 || n < -2147483648)
		ft_exit("Error", 1);
	while (tmp)
	{
		if ((long)tmp->content == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void take_arg(char **part, t_struct *ps)
{
	int j;

	j = -1;
	while (part[++j])
	{
		if (!is_valid(part[j]))
			ft_exit("Error", 1);
		if (duplicate(ps->lst_a, ft_atol(part[j])))
			ft_exit("Error", 1);
		lst_push_back(ps->lst_a, new_lst((void *)ft_atol(part[j])));
	}
}

void parse(char **av, t_struct *ps, int i)
{
	char **part;

	init_struct(ps);
	while (av[++i])
	{
		if (i < 3 && !ft_strcmp(av[i], "-v") && !ps->flag)
			ps->debug = 1;
		else if (i < 3 && !ft_strcmp(av[i], "-c") && !ps->flag)
			ps->color = 1;
		else
		{
			ps->flag = 1;
			part = ft_split(av[i], ' ');
			if (!part[0])
				ft_exit("Error", 1);
			take_arg(part, ps);
		}
	}
	ps->size = lst_size(ps->lst_a);
}
