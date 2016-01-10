/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:08:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/09 14:58:36 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	map;

	if (ac == 2)
	{
		file(av[1], &map);
		printf("line : %d \n collum : %d \n", map.line, map.collum);
		ft_print_2d_tab(map.cor, map.line, map.collum);
		map.basex = 450;
		map.basey = 450;
		map.size = 10;
		window(&map);
	}
	else
		ft_exit("Bad Numbers Of Args");
}
