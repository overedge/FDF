/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 17:08:03 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/07 21:00:31 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_map	map;

		file(av[1], &map);
//		window(&map);
		printf("line : %d \n collum : %d \n", map.line, map.collum);
		ft_print_2d_tab(map.cor, map.line, map.collum);
	}
	else
		ft_exit("Bad Numbers Of Args");
}
