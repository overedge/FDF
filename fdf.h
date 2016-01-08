/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:29 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/08 19:50:55 by nahmed-m         ###   ########.fr       */
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
# define X_WIN 800
# define Y_WIN 800

/*
** Map Of Keyboard
*/
# define ESC 53
# define TOP 126
# define BOT 125
# define LEFT 123
# define RIGHT 124
# define ZOOM 69

typedef struct	s_env
{
	int		**cor;
	int		line;
	int		collum;
	void	*mlx;
	void	*win;
	void	*image;
	int		zoom;
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

#endif
