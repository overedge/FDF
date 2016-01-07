/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 20:23:07 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/07 21:00:33 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *error)
{
	ft_putendl_fd(error, 2);
	exit(0);
}

void	ft_print_2d_tab(int **tab, int line, int collum)
{
	int		i;
	int		j;

	i = 0;
	while (i != line)
	{
		j = 0;
		while (j != collum)
		{
			ft_putnbr(tab[i][j]);
			ft_putstr("  ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}
