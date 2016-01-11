/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:08:47 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/11 15:18:27 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line(int x0, int y0, int x1, int y1, t_env *map, int color)
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

static void ft_black_screen(t_env *map)
{
	int y;

	y = 0;
	while (y < Y_WIN)
	{
		line(0, y, X_WIN, y, map, 0x000000);
		y++;
	}
}

static int color(int i)
{
	if (i <= 0)
		return (0x0000FF); // BLEU OK
	if (i <= 2)
		return (0xFFFF00); // JAUNE
	if (i <= 30)
		return (0x00FF00); //VERT
	if (i <= 40)
		return (0x33CCFF);//BLEU CIEL
	if (i <= 50)
		return (0x993300);  // Marron // OK
	if (i > 50)
		return (0xFFFFFF);  // BLANC // OK
	return (0xFF00FF);
}
static void ft_generate_x_axes(t_env *e, int iso, int size, t_trace *t)
{
	int		c;
	while (t->k != e->line)
	{
		while (t->i != e->collum - 1)
		{
			c = e->cor[t->k][t->i];
			if (e->cor[t->k][t->i] == e->cor[t->k][t->i + 1])
				line(t->x + iso, t->y - e->cor[t->k][t->i], t->x + size + iso, t->y - e->cor[t->k][t->i], e, color(c));
			if (e->cor[t->k][t->i] < e->cor[t->k][t->i + 1])
				line(t->x + iso, t->y, t->x + size + iso, t->y - e->cor[t->k][t->i + 1], e, color(c));
			if (e->cor[t->k][t->i] > e->cor[t->k][t->i + 1])
				line(t->x + iso, t->y - e->cor[t->k][t->i], t->x + size + iso, t->y, e, color(c));
			t->x += size;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += size;
		iso -= size;
	}
}

static void		ft_generate_y_axes(t_env *e, int iso, int size, t_trace *t)
{
	int		c;
	while (t->k != e->line - 1)
	{
		while (t->i != e->collum)
		{
			c = e->cor[t->k][t->i];
			if (e->cor[t->k][t->i] == e->cor[t->k + 1][t->i])
				line(t->x + iso, t->y - e->cor[t->k][t->i], t->x + iso - size, t->y + size - e->cor[t->k][t->i], e, color(c));
			if (e->cor[t->k][t->i] < e->cor[t->k + 1][t->i])
				line(t->x + iso, t->y, t->x + iso - size, t->y + size - e->cor[t->k + 1][t->i], e, color(c));
			if (e->cor[t->k][t->i] > e->cor[t->k + 1][t->i])
				line(t->x + iso, t->y - e->cor[t->k][t->i], t->x + iso - size, t->y + size, e, color(c));
			t->x += size;
			t->i++;
		}
		t->x = e->basex;
		t->i = 0;
		t->k++;
		t->y += size;
		iso -= size;
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
	return (0);
}
