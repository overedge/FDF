/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/13 18:01:47 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define NAME "fdf"
# define X_WIN 1000
# define Y_WIN 1000

/*
** Map Of Keyboard
*/
# define ESC 53
# define TOP 126
# define BOT 125
# define LEFT 123
# define RIGHT 124
# define ZOOM 69
# define DEZOOM 78
# define ELEVATE 31
# define DOWN 37

/*
** Colors Defines
*/
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define GREEN 0x00FF00
# define TURQ 0x33CCFF
# define BROWN 0x993300
# define WHITE 0xFFFFFF

typedef struct	s_env
{
	int		**cor;
	int		line;
	int		collum;
	void	*mlx;
	void	*win;
	int		basex;
	int		basey;
	int		size;
	char	*filename;
	int		color;
}				t_env;

typedef struct	s_trace
{
	int i;
	int k;
	int x;
	int y;
}				t_trace;

typedef struct	s_cor
{

	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}				t_cor;

typedef struct	s_pos
{
	int x;
	int y;
}				t_pos;
/*
** Window fuctions
*/
void			window(t_env *win);

/*
** Draw fuctions
*/
int				draw(t_env *map);
void			line(t_pos *p1, t_pos *p2, t_env *map);
void			ft_gen_x_axes_mid(t_env *e, int i, int s, t_trace *t);
void			ft_gen_x_axes_top(t_env *e, int i, int s, t_trace *t);
void			ft_gen_y_axes_mid(t_env *e, int i, int s, t_trace *t);
void			ft_gen_y_axes_top(t_env *e, int i, int s, t_trace *t);

/*
** File fuctions
*/
void			file(char *av, t_env *map);

/*
** Keyboard fuctions
*/
int				keyboard(int keycode, t_env *map);
/*
** Utils fuctions
*/
void			ft_exit(char *error);
void			ft_print_2d_tab(int **tab, int line, int collum);
void			ft_modify_tab(t_env *control, int ratio);
int				color(int i);
void			ft_black_screen(t_env *map);
/*
** Overlay fuctions
*/
void			ft_set_overlay(t_env *e);

#endif
