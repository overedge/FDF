/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 21:35:59 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/13 16:56:42 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_overlay(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 20, 0xFF0000, "File :");
	mlx_string_put(e->mlx, e->win, 90, 20, 0xFF0000, e->filename);
	mlx_string_put(e->mlx, e->win, 20, 40, 0xFF0000, "Commands :");
	mlx_string_put(e->mlx, e->win, 20, 60, 0xFF0000, "arrows = MOVE");
	mlx_string_put(e->mlx, e->win, 20, 80, 0xFF0000, "+/- (pavnum) = ZOOM");
	mlx_string_put(e->mlx, e->win, 20, 100, 0xFF0000, "o/l  = Increase \
			/ Decrease");
	mlx_string_put(e->mlx, e->win, 20, 120, 0xFF0000, "ECS = QUIT");
}
