/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:50:45 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/08 17:07:14 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window(t_env *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, X_WIN, Y_WIN, NAME);
	mlx_expose_hook(win->win, draw, &*win);
	mlx_key_hook(win->win, keyboard, &*win);
	mlx_loop(win->mlx);
}
