#include "push_swap.h"

int	get_from_top(t_list **lst, long start, long end)
{
	t_list	*tmp;
	long	n;
	int		i;

	tmp = *lst;
	i = -1;
	while (tmp && ++i < (lst_size(lst) / 2))
	{
		n = (long)tmp->content;
		if (n >= start && n < end)
			return (++i);
		tmp = tmp->next;
	}
	return (IMPOSSIBLE);
}

int	get_from_bot(t_list **lst, long start, long end)
{
	t_list	*tmp;
	long	n;
	int		i;

	i = lst_size(lst);
	tmp = get_at_pos(lst, i - 1);
	while (tmp && --i >= (lst_size(lst) / 2))
	{
		n = (long)tmp->content;
		if (n >= start && n < end)
			return (lst_size(lst) - i - 1);
		tmp = get_at_pos(lst, i);
	}
	return (IMPOSSIBLE);
}

int	get_at_top(int top, int bot, t_struct *ps)
{
	if (top == IMPOSSIBLE && bot == IMPOSSIBLE)
		return (0);
	else if (top == IMPOSSIBLE || (bot < top))
	{
		while ((long)get_at_pos(ps->lst_a, 0)->content < ps->start
			|| (long)get_at_pos(ps->lst_a, 0)->content >= ps->end)
			reverse_rotate(ps->lst_a, ps, 1, 1);
		push(ps->lst_b, ps->lst_a, ps, 0);
	}
	else if (bot == IMPOSSIBLE || (bot >= top))
	{
		while ((long)get_at_pos(ps->lst_a, 0)->content < ps->start
			|| (long)get_at_pos(ps->lst_a, 0)->content >= ps->end)
			rotate(ps->lst_a, ps, 1, 1);
		push(ps->lst_b, ps->lst_a, ps, 0);
	}
	return (1);
}

void	empty_chunk_a(t_struct *ps)
{
	int	top;
	int	bot;

	while (lst_size(ps->lst_a))
	{
		top = get_from_top(ps->lst_a, ps->start, ps->end);
		bot = get_from_bot(ps->lst_a, ps->start, ps->end);
		if (!get_at_top(top, bot, ps))
			raise_plage(ps);
	}
}

void	fill_sorted_a(t_struct *ps)
{
	t_list	**b;

	b = ps->lst_b;
	while (lst_size(b))
	{
		ps->start = get_max(b);
		ps->end = ps->start + 1;
		if (get_pos(b, get_max(b)) <= lst_size(b) / 2)
		{
			while (!is_top_max(b))
				rotate(b, ps, 1, 0);
		}
		if (get_pos(b, get_max(b)) > lst_size(b) / 2)
			while (!is_top_max(b))
				reverse_rotate(b, ps, 1, 0);
		push(ps->lst_a, b, ps, 1);
	}
}
