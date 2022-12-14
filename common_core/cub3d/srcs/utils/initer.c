/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azod     <contact@azod.io>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 11:54:20 by azod              #+#    #+#             */
/*   Updated: 2021/01/05 10:48:23 by azod             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cubeddd.h"

void init_variables(t_display *d, t_params *p, int x)
{
	d->cam_z = (0.5 * p->win_y - d->pos_z);
	d->p = (0.5 * p->win_y + d->pitch);
	d->rowdist = d->cam_z / d->p;
	d->camera_x = (2 * x / (double)p->win_x - 1);
	d->raydir_x = d->dir_x + d->plane_x * d->camera_x;
	d->raydir_y = d->dir_y + d->plane_y * d->camera_x;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
	d->deltadist_x = fabs(1 / d->raydir_x);
	d->deltadist_y = fabs(1 / d->raydir_y);
	d->hit = 0;
}

t_all init_texture(t_params p, t_all a, int i)
{
	t_texture t;
	int w;
	int h;
	int sizeline;

	while (++i < 7)
	{
		t.ptr = mlx_xpm_file_to_image(a.mlx.ptr, get_path(i, p), &w, &h);
		t.info[1] = w;
		t.info[2] = h;
		t.array = (int *)mlx_get_data_addr(t.ptr, &w, &sizeline, &h);
		t.info[0] = sizeline;
		t.info[3] = w;
		a.text[i] = t;
	}
	a.life_txt = mlx_xpm_file_to_image(a.mlx.ptr, "txt/heart.xpm", &w, &h);
	return (a);
}

t_all init_key(t_all all)
{
	all.key.w = 0;
	all.key.a = 0;
	all.key.s = 0;
	all.key.d = 0;
	all.key.hud = 0;
	all.key.right = 0;
	all.key.left = 0;
	all.sprint = 0;
	all.keys = 0;
	all.life = 3;
	return (all);
}

t_display init_display(t_map map)
{
	t_display d;
	double rota;
	double oldir_x;
	double oldplane;

	d.pos_x = map.pos[0] + 0.5;
	d.pos_y = map.pos[1] + 0.5;
	d.pos_z = 0;
	d.pitch = 0;
	rota = get_rotation(map.p_facing);
	d.dir_x = -1;
	d.dir_y = 0;
	oldir_x = d.dir_x;
	d.dir_x = d.dir_x * cos(-rota) - d.dir_y * sin(-rota);
	d.dir_y = oldir_x * sin(-rota) + d.dir_y * cos(-rota);
	d.plane_x = 0;
	d.plane_y = 0.66;
	oldplane = d.plane_x;
	d.plane_x = d.plane_x * cos(-rota) - d.plane_y * sin(-rota);
	d.plane_y = oldplane * sin(-rota) + d.plane_y * cos(-rota);
	return (d);
}

t_all init_all(t_all all)
{
	all.d = init_display(all.map);
	all.mlx.ptr = mlx_init();
	all = init_texture(all.p, all, -1);
	all = init_key(all);
	return (all);
}
