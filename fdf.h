/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/12 18:05:41 by nahmed-m         ###   ########.fr       */
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
}				t_env;

typedef struct s_trace
{
	int i;
	int	k;
	int x;
	int y;
}				t_trace;
/*
** Window fuctions
*/
void			window(t_env *win);

/*
** Draw fuctions
*/
int				draw(t_env *map);
void			line(int x0, int y0, int x1, int y1, t_env *map, int color);

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
void			ft_modify_tab(t_env *control,    int ratio);
int				color(int i);
void			ft_black_screen(t_env *map);
#endif
