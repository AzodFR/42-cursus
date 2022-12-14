/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:12:12 by azod              #+#    #+#             */
/*   Updated: 2021/01/05 15:24:49 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cubeddd.h"

void print_ceil(int *array, t_display *d, t_params *p, int x)
{
	long color;
	int i;

	i = -1;
	color = p->c[2] + p->c[1] * 16 * 16 + p->c[0] * 16 * 16 * 16 * 16;
	while (++i <= d->draw_start)
		array[i * p->win_x + x] = color;
}

void print_floor(int *array, t_display *d, t_params *p, int x)
{
	long color;
	int i;

	i = d->draw_end;
	color = p->f[2] + p->f[1] * 16 * 16 + p->f[0] * 16 * 16 * 16 * 16;
	while (i <= (p->win_y - 1))
		array[i++ * p->win_x + x] = color;
}

void print_wall(int *array, t_all *all, int x, int or)
{
	int y;
	t_display *d;
	t_params *p;
	long color;

	d = &(all->d);
	p = &(all->p);
	y = d->draw_start;
	while (y < d->draw_end)
	{
		d->tex_y = (int)d->tex_pos & (all->text[or].info[2] - 1);
		d->tex_pos += d->step;
		color = all->text[or].array[all->text[or].info[2] *
										d->tex_y +
									d->tex_x];
		if (d->lineheight < 150)
			color = (color >> 1) & 8355711;
		if (d->lineheight < 100)
			color = (color >> 1) & 7355000;
		array[y * p->win_x + x] = color;
		y++;
	}
}

void print_sprite(int *array, t_all *all, t_display *d)
{
	int i;
	int type;

	i = all->map.nbsprite;
	while (--i >= 0)
	{
		type = get_type(all, d, i);
		check_start_end(all, d);
		d->stripe = d->drawstart_x;
		while (d->stripe < d->drawend_x)
			draw_sprite(all, d, type, array);
	}
	if (all->p.screen == 1)
		ft_init_bmp(all, all->p.win_x, all->p.win_y, array);
}
