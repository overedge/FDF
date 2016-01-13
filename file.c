/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:54:37 by nahmed-m          #+#    #+#             */
/*   Updated: 2016/01/13 14:04:59 by nahmed-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_line(char *av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit("File not exist or is Directory");
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

static int	ft_count_collum(char *av)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit("File not exist or is Directory");
	get_next_line(fd, &line);
	tab = ft_strsplit(line, ' ');
	while (get_next_line(fd, &line))
		free(line);
	free(line);
	while (tab[i])
		i++;
	free(tab);
	close(fd);
	return (i);
}

static void	ft_insertdata(t_env *map, int fd)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	while (i != map->line)
	{
		j = 0;
		get_next_line(fd, &line);
		tab = ft_strsplit(line, ' ');
		while (tab[j])
			j++;
		if (j != map->collum)
			ft_exit("Check You Collum map file");
		map->cor[i] = (int *)malloc(sizeof(int) * map->collum);
		j = 0;
		while (tab[j])
		{
			map->cor[i][j] = ft_atoi(tab[j]);
			j++;
		}
		i++;
	}
}

void		file(char *av, t_env *map)
{
	int		fd;

	map->line = ft_count_line(av);
	map->collum = ft_count_collum(av);
	map->cor = (int **)malloc(sizeof(int*) * map->line);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit("File not exist or is Directory");
	ft_insertdata(&*map, fd);
	close(fd);
}
