/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:08:47 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/12 21:41:49 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(int x0, int y0, int x1, int y1, t_env *map, int color)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = ft_abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = ft_abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(map->mlx, map->win, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

static void ft_generate_x_axes(t_env *e, int i, int s, t_trace *t)
{
	int		c;

	while (t->k != e->line)
	{
		while (t->i != e->collum - 1)
		{
			c = e->cor[t->k][t->i];
			if (e->cor[t->k][t->i] == e->cor[t->k][t->i + 1])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + s + i, t->y \
					- e->cor[t->k][t->i], e, color(c));
			else if (e->cor[t->k][t->i] < e->cor[t->k][t->i + 1])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + s + i, t->y \
					- e->cor[t->k][t->i + 1], e, color(c));
			else if (e->cor[t->k][t->i] > e->cor[t->k][t->i + 1])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + s + i, t->y \
					- e->cor[t->k][t->i + 1], e, color(c));
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}

static void		ft_generate_y_axes(t_env *e, int i, int s, t_trace *t)
{
	int		c;

	while (t->k != e->line - 1)
	{
		while (t->i != e->collum)
		{
			c = e->cor[t->k][t->i];
			if (e->cor[t->k][t->i] == e->cor[t->k + 1][t->i])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + i - s, t->y \
					+ s - e->cor[t->k][t->i], e, color(c));
			else if (e->cor[t->k][t->i] < e->cor[t->k + 1][t->i])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + i - s, t->y \
					+ s - e->cor[t->k + 1][t->i], e, color(c));
			else if (e->cor[t->k][t->i] > e->cor[t->k + 1][t->i])
				line(t->x + i, t->y - e->cor[t->k][t->i], t->x + i - s, t->y \
					+ s - e->cor[t->k + 1][t->i], e, color(c));
			t->x += s;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += s;
		i -= s;
	}
}

int			draw(t_env *map)
{
	t_trace trace;

	trace.i = 0;
	trace.k = 0;
	trace.x = map->basex;
	trace.y = map->basey;
	ft_black_screen(map);
	ft_generate_x_axes(map, 200, map->size, &trace);
	trace.i = 0;
	trace.k = 0;
	trace.x = map->basex;
	trace.y = map->basey;
	ft_generate_y_axes(map, 200, map->size, &trace);
	ft_set_overlay(map);
	return (0);
}
