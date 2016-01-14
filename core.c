/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:08:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/14 13:05:08 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	map;

	if (ac == 2)
	{
		file(av[1], &map);
		ft_print_2d_tab(map.cor, map.line, map.collum);
		map.basex = 450;
		map.basey = 450;
		map.size = 10;
		map.filename = av[1];
		window(&map);
	}
	else
		ft_exit("Usage : ./fdf <path_of_map>");
}
