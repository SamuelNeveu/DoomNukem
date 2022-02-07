/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static void		get_neighbourpos(t_doom *data, int x, int y)
{
	int		pos;

	pos = x + y * data->map.width;
	data->pfdata.list[pos].ngbhr[0] = NULL;
	data->pfdata.list[pos].ngbhr[1] = NULL;
	data->pfdata.list[pos].ngbhr[2] = NULL;
	data->pfdata.list[pos].ngbhr[3] = NULL;
	if (y > 0)
		data->pfdata.list[pos].ngbhr[0] = &data->pfdata.list[(x + 0)
			+ data->map.width * (y - 1)];
	if (y < data->map.height - 1)
		data->pfdata.list[pos].ngbhr[1] = &data->pfdata.list[(x + 0)
			+ data->map.width * (y + 1)];
	if (x > 0)
		data->pfdata.list[pos].ngbhr[2] = &data->pfdata.list[(x - 1)
			+ data->map.width * (y + 0)];
	if (x < data->map.width - 1)
		data->pfdata.list[pos].ngbhr[3] = &data->pfdata.list[(x + 1)
			+ data->map.width * (y + 0)];
}

void			get_nodes(t_doom *data)
{
	int	i;
	int	x;
	int	y;

	if (!(data->pfdata.list = (t_node *)ft_memalloc(sizeof(t_node)
	* (data->map.len))))
		clean_exit(data, "malloc error", 0);
	i = 0;
	x = -1;
	while (++x < data->map.width)
	{
		y = -1;
		while (++y < data->map.height)
		{
			data->pfdata.list[i].i = i;
			++i;
			data->pfdata.list[y * data->map.width + x].x = x;
			data->pfdata.list[y * data->map.width + x].y = y;
			if (data->map.map[x][y] == 1)
				data->pfdata.list[y * data->map.width + x].bobstacle = 1;
			get_neighbourpos(data, x, y);
		}
	}
}
