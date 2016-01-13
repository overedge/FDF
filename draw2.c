/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:17:24 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/13 18:01:43 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_gen_axes_mid(t_env *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;
	while (t->k != e->line)
	{
		while(t->i != e->collum - 1)
		{
			e->color = color(e->cor[t->k][t->i]);
			if (e->cor[t->k][t->i] == e->cor[t->k][t->i + 1])
			{
				
				line(&p1, &p2, e);
			}
		}
	}

}
