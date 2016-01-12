/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:14:59 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/12 17:25:13 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_key(int keycode, t_env *control)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == RIGHT)
		control->basex += 10;
	else if (keycode == LEFT)
		control->basex -= 10;
	else if (keycode == TOP)
		control->basey -= 10;
	else if (keycode == BOT)
		control->basey += 10;
	else if (keycode == ZOOM)
		control->size += 5;
	else if (keycode == DEZOOM)
		control->size -= 5;
	else if (keycode == ELEVATE)
		ft_modify_tab(control, 1);
	else if (keycode == DOWN)
		ft_modify_tab(control, 0);
	else
		return ;
	draw(control);
}

int			keyboard(int keycode, t_env *map)
{
	printf("key : %d\n", keycode);
	map_key(keycode, map);
	return (0);
}
