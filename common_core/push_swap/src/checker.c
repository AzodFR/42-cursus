/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 06:44:24 by azod              #+#    #+#             */
/*   Updated: 2021/03/29 06:44:24 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void push2(t_list **dest, t_list **src)
{
	t_list *tmp;

	if (!lst_size(src))
		return;
	tmp = new_lst((*src)->content);
	(*src) = (*src)->next;
	lst_push_front(dest, tmp);
}

void handler(char *s, t_struct *ps)
{
	if (!ft_strcmp(s, "sa"))
		swap(ps->lst_a, ps, 0, 0);
	else if (!ft_strcmp(s, "sb"))
		swap(ps->lst_b, ps, 0, 0);
	else if (!ft_strcmp(s, "ss"))
		double_swap(&ps, 0);
	else if (!ft_strcmp(s, "pa"))
		push2(ps->lst_a, ps->lst_b);
	else if (!ft_strcmp(s, "pb"))
		push2(ps->lst_b, ps->lst_a);
	else if (!ft_strcmp(s, "ra"))
		rotate(ps->lst_a, ps, 0, 0);
	else if (!ft_strcmp(s, "rb"))
		rotate(ps->lst_b, ps, 0, 0);
	else if (!ft_strcmp(s, "rr"))
		double_rotate(&ps, 0);
	else if (!ft_strcmp(s, "rra"))
		reverse_rotate(ps->lst_a, ps, 0, 0);
	else if (!ft_strcmp(s, "rrb"))
		reverse_rotate(ps->lst_b, ps, 0, 0);
	else if (!ft_strcmp(s, "rrr"))
		double_rev_rotate(&ps, 0);
	else
		ft_exit("Error", 1);
	wrfree(s);
}

int parse2(char **av, t_struct *ps, int i)
{
	char **part;
	int file;

	init_struct(ps);
	file = 0;
	while (av[++i])
	{
		if (i < 3 && !ft_strcmp(av[i], "-f") && !ps->flag)
			file = ++i;
		else if (++(ps->flag))
		{
			part = ft_split(av[i], ' ');
			if (!part[0])
				ft_exit("Error", 1);
			take_arg(part, ps);
		}
	}
	ps->size = lst_size(ps->lst_a);
	return (file);
}

int get_param(int ac, int fd, char **av, t_struct *ps)
{
	if (ac < 2)
		ft_exit("Error", 1);
	if (parse2(av, ps, 0))
	{
		fd = open(av[2], O_RDONLY);
		if (fd < 0)
			ft_exit("Error", 1);
	}
	return (fd);
}

int main(int ac, char **av)
{
	int fd;
	char *line;
	int ret;
	t_struct *ps;

	if (ac < 2)
		return (0);
	ps = wrmalloc(sizeof(t_struct));
	fd = get_param(ac, 0, av, ps);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		handler(line, ps);
		ret = get_next_line(fd, &line);
	}
	if (is_sort(ps))
		ft_exit("OK", 0);
	ft_exit("KO", 1);
	return (0);
}
