/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:14:59 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/09 14:47:24 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_key(int keycode, t_env *control)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
	{
		control->basex += 10;
		draw(control);
	}
	if (keycode == LEFT)
	{
		control->basex -= 10;
		draw(control);
	}
	if (keycode == TOP)
	{
		control->basey -= 10;
		draw(control);
	}
	if (keycode == BOT)
	{
		control->basey += 10;
		draw(control);
	}
}

int			keyboard(int keycode, t_env *map)
{
	printf("key : %d\n", keycode);
	map_key(keycode, map);
	return (0);
}
