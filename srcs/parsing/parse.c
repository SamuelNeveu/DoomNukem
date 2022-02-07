/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:07:52 by qbenaroc          #+#    #+#             */
/*   Updated: 2020/08/01 22:23:55 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

size_t		ft_countcwords(const char *s, char c)
{
	int		i;
	size_t	wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wordcount++;
		i++;
	}
	return (wordcount);
}

int			check_map(t_doom *e, t_map *map, int fd)
{
	if (!check_player(map))
		return (display_error(e, ERROR_PLAYER));
	if (!check_wall_surround(map))
		return (display_error(e, ERROR_WALL));
	if (!check_win(map))
		return (display_error(e, ERROR_WIN));
	if (close(fd) == -1)
		return (display_error(e, ERROR_CLOSE));
	return (1);
}

int			*fill_number(t_map *map, char *line)
{
	int		j;
	int		*nb;
	char	**split;

	if ((map->height = ft_countcwords(line, ' ')) <= 1)
		return (NULL);
	if (!(nb = (int*)malloc(sizeof(int) * map->height)))
		return (NULL);
	if ((split = ft_strsplit(line, ' ')) == NULL)
		return (NULL);
	j = -1;
	while (++j < map->height)
	{
		if ((nb[j] = ft_atoi(split[j])) < 0)
			return (NULL);
	}
	free_split(split);
	return (nb);
}

int			**fill_tab(t_map *map, int fd)
{
	char	*line;
	int		ret;
	int		i;
	int		**m;

	if (!(m = (int**)malloc(sizeof(int*) * map->width)))
		return (NULL);
	i = -1;
	while ((ret = get_next_line(fd, &line)) && ++i < map->width)
	{
		if (!check_line(line) || !(m[i] = fill_number(map, line)))
		{
			free_int(m, i);
			free(line);
			return (NULL);
		}
		free(line);
	}
	return (m);
}

int			parse(t_doom *e, char *av)
{
	int		fd;
	t_map	map;
	char	*line;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (display_error(e, ERROR_OPEN));
	map.width = 0;
	while (get_next_line(fd, &line))
	{
		map.width++;
		free(line);
	}
	close(fd);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (display_error(e, ERROR_OPEN));
	if ((map.map = fill_tab(&map, fd)) == NULL)
		return (display_error(e, ERROR_MAP));
	check_map(e, &map, fd);
	e->map = map;
	return (1);
}
