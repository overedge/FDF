/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:19:23 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/13 14:04:53 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(t_cor *p, t_env *map, int color)
{
	t_cor t;

	t.dx = ft_abs(p->x1 - p->x0);
	t.sx = p->x0 < p->x1 ? 1 : -1;
	t.dy = ft_abs(p->y1 - p->y0);
	t.sy = p->y0 < p->y1 ? 1 : -1;
	t.err = (t.dx > t.dy ? t.dx : -t.dy) / 2;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->win, p->x0, p->y0, color);
		if (p->x0 == p->x1 && p->y0 == p->y1)
			break ;
		t.e2 = t.err;
		if (t.e2 > -t.dx)
		{
			t.err -= t.dy;
			p->x0 += t.sx;
		}
		if (t.e2 < t.dy)
		{
			t.err += t.dx;
			p->y0 += t.sy;
		}
	}
}
