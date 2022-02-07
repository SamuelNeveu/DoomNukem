/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <qbenaroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 16:38:42 by qbenaroc          #+#    #+#             */
/*   Updated: 2020/08/01 21:16:02 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	free_int(int **map, int width)
{
	int i;

	i = -1;
	while (++i < width)
		free(map[i]);
	free(map);
	map = NULL;
}

void	free_list(t_list *list)
{
	t_list *next;

	if (list != NULL)
	{
		while (list != NULL)
		{
			next = list->next;
			free(list->content);
			list->next = NULL;
			free(list);
			list = next;
		}
	}
}

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (split != NULL)
	{
		while (split[i] != NULL)
		{
			free((split[i]));
			i++;
		}
		free(split);
	}
}

void	free_map(t_map *map)
{
	int		i;

	i = 0;
	if (map != NULL && map->map != NULL)
	{
		while (i < map->width)
		{
			if (map->map[i] != NULL)
				free((map->map[i]));
			i++;
		}
		free(map->map);
		free(map);
	}
}
