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

void		ft_gen_x_axes_mid(t_env *e, int i, int s, t_trace *t)
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
				p1.x = t->x + i,
				p1.y = t->y - e->cor[t->k][t->i],
				p2.x = t->x + s + i,
				p2.y = t->y - e->cor[t->k][t->i],
				line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
	t->x = e->basex;
	t->i = 0;
	t->k++;
	t->y += s;
	i -= s;
	}
}

void		ft_gen_x_axes_top(t_env *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;
	while (t->k != e->line)
	{
		while(t->i != e->collum - 1)
		{
			e->color = color(e->cor[t->k][t->i]);
			if (e->cor[t->k][t->i] != e->cor[t->k][t->i + 1])
			{
				p1.x = t->x + i,
				p1.y = t->y - e->cor[t->k][t->i],
				p2.x = t->x + s + i,
				p2.y = t->y - e->cor[t->k][t->i + 1],
				line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
	t->x = e->basex;
	t->i = 0;
	t->k++;
	t->y += s;
	i -= s;
	}
}

void		ft_gen_y_axes_mid(t_env *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;
	while (t->k != e->line - 1)
	{
		while(t->i != e->collum)
		{
			e->color = color(e->cor[t->k][t->i]);
			if (e->cor[t->k][t->i] == e->cor[t->k + 1][t->i])
			{
				p1.x = t->x + i,
				p1.y = t->y - e->cor[t->k][t->i],
				p2.x = t->x + i - s,
				p2.y = t->y + s - e->cor[t->k][t->i],
				line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
	t->x = e->basex;
	t->i = 0;
	t->k++;
	t->y += s;
	i -= s;
	}
}

void		ft_gen_y_axes_top(t_env *e, int i, int s, t_trace *t)
{
	t_pos p1;
	t_pos p2;
	while (t->k != e->line - 1)
	{
		while(t->i != e->collum)
		{
			e->color = color(e->cor[t->k][t->i]);
			if (e->cor[t->k][t->i] != e->cor[t->k + 1][t->i])
			{
				p1.x = t->x + i,
				p1.y = t->y - e->cor[t->k][t->i],
				p2.x = t->x + i - s,
				p2.y = t->y + s - e->cor[t->k + 1][t->i],
				line(&p1, &p2, e);
			}
			t->x += s;
			t->i++;
		}
	t->x = e->basex;
	t->i = 0;
	t->k++;
	t->y += s;
	i -= s;
	}
}
