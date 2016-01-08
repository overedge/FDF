/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 20:14:59 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/08 19:45:15 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_key(int keycode, t_env *control)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == ZOOM)
	{
		control->zoom += 10;
		draw(control);
	}
}

int			keyboard(int keycode, t_env *map)
{
	map->collum++;
	printf("key : %d\n", keycode);
	map_key(keycode, map);
	return (0);
}
