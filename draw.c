/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:08:47 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/09 16:37:52 by nahmed-m         ###   ########.fr       */
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

int			draw(t_env *map)
{
	ft_black_screen(map);

	int i;
	int k;
	int x;
	int y;
	int	size = map->size;


	int iso = 200;
	i = 0;
	k = 0;
	x = map->basex;
	y = map->basey;

	while(k != map->line)
	{
		while(i != map->collum - 1)
		{
			if (map->cor[k][i] == map->cor[k][i + 1])
				line(x + iso, y - map->cor[k][i], x + size + iso, y - map->cor[k][i], map, 0xFF0000);
			if (map->cor[k][i] < map->cor[k][i + 1])
				line(x + iso, y, x + size + iso,  y - map->cor[k][i + 1], map, 0x00FF00);
			if (map->cor[k][i] > map->cor[k][i + 1])
				line(x + iso, y - map->cor[k][i], x + size + iso,  y, map, 0x00FF00);
			x += size;
			i++;
		}
			x = map->basex;
			i = 0;
			k++;
			y += size;
			iso -= size;
	}

	i = 0;
	k = 0;
	x = map->basex;
	y = map->basey;
	iso = 200;
	while(k != map->line - 1)
	{
		while(i != map->collum)
		{
			if (map->cor[k][i] == map->cor[k + 1][i])
				line(x + iso, y - map->cor[k][i], x + iso - size, y + size - map->cor[k][i], map, 0xFF0000);
			if (map->cor[k][i] < map->cor[k + 1][i])
				line(x + iso, y, x + iso - size, y + size - map->cor[k + 1][i],  map, 0x00FF00);
			if (map->cor[k][i] > map->cor[k + 1][i])
				line(x + iso, y - map->cor[k][i], x + iso - size, y + size, map, 0x00FF00);
		 x += size;
		 i++;
		}
			x = map->basex;
			i = 0;
			k++;
			y += size;
			iso -= size;
	}
	return (0);
}
