/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/09 14:22:40 by nahmed-m         ###   ########.fr       */
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

/*
** Window fuctions
*/
void			window(t_env *win);

/*
** Draw fuctions
*/
int				draw(t_env *map);

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
#endif
