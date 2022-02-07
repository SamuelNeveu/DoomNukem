/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:10:16 by qbenaroc          #+#    #+#             */
/*   Updated: 2020/08/01 20:26:25 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		check_line(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int		check_wall_surround(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height)
		{
			if (i == 0 && (map->map[i][j] != WALL
				&& map->map[i][j] != WALL1 && map->map[i][j] != WALL2))
				return (0);
			if (i == map->width - 1 && (map->map[i][j] != WALL
				&& map->map[i][j] != WALL1 && map->map[i][j] != WALL2))
				return (0);
			if (j == 0 && (map->map[i][j] != WALL
				&& map->map[i][j] != WALL1 && map->map[i][j] != WALL2))
				return (0);
			if (j == map->height - 1 && (map->map[i][j] != WALL
				&& map->map[i][j] != WALL1 && map->map[i][j] != WALL2))
				return (0);
		}
	}
	return (1);
}

int		check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->map[i][j] == PLAYER)
			{
				map->posx = j;
				map->posy = i;
				map->map[i][j] = 0;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		check_win(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[j][i] == WIN)
				count++;
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
