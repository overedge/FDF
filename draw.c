/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:08:47 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/14 11:56:44 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			line(t_pos *p1, t_pos *p2, t_env *map)
{
	t_cor t;

	t.dx = ft_abs(p2->x - p1->x);
	t.sx = p1->x < p2->x ? 1 : -1;
	t.dy = ft_abs(p2->y - p1->y);
	t.sy = p1->y < p2->y ? 1 : -1;
	t.err = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->win, p1->x, p1->y, map->color);
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		t.e2 = t.err;
		if (t.e2 > -t.dx)
		{
			t.err -= t.dy;
			p1->x += t.sx;
		}
		if (t.e2 < t.dy)
		{
			t.err += t.dx;
			p1->y += t.sy;
		}
	}
}

static void		ft_selector_ft(int i, t_env *e, int iso, t_trace *t)
{
	if (i == 0)
		ft_gen_x_axes_mid(e, iso, e->size, t);
	if (i == 1)
		ft_gen_x_axes_top(e, iso, e->size, t);
	if (i == 2)
		ft_gen_y_axes_mid(e, iso, e->size, t);
	if (i == 3)
		ft_gen_y_axes_top(e, iso, e->size, t);
}

int				draw(t_env *map)
{
	int		i;
	t_trace trace;

	i = 0;
	ft_black_screen(map);
	while (i <= 3)
	{
		trace.i = 0;
		trace.k = 0;
		trace.x = map->basex;
		trace.y = map->basey;
		ft_selector_ft(i, map, 200, &trace);
		i++;
	}
	ft_set_overlay(map);
	return (0);
}
