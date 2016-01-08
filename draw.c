/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:08:47 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/08 21:05:01 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line(int x0, int y0, int x1, int y1, t_env *map)
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
		mlx_pixel_put(map->mlx, map->win, x0, y0, 0xFF0000);
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

int			draw(t_env *map)
{
	int		i;
	int		k;
	int		x;
	int		y;

	i = 0;
	k = 0;
	x = 10;
	y = 30;
	while(k != map->line - 1)
	{
		while(i != map->collum)
		{
		//	AXE X
			if (map->cor[k][i] == map->cor[k][i + 1])
				line(x, y, x + 20, y, map);
			if (map->cor[k][i] < map->cor[k][i + 1])
				line(x, y, x + 20, y + 30, map);
			//AXE Y
			if (map->cor[k][i] == map->cor[k + 1][i])
				line(x, y, x, y + 30, map);
			if (map->cor[k][i] < map->cor[k + 1][i])
				line(x, y, x + 20, y + 30, map);
			x += 20;
			i++;
		}
		x = 10;
		i = 0;
		k++;
		y += 30;
	}
	return (0);
}
