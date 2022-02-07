/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:47:19 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static void		draw_ray_fov(t_doom *data, int i, int x, int y)
{
	SDL_SetRenderDrawColor(data->renderer, 155, 0, 150, 100);
	SDL_RenderDrawLine(data->renderer, x, y,
			data->map.depth_buffer[i]
			* W_WIDTH / (data->map.sc_x * data->map.width)
			* (data->player.dirx) + x, data->map.depth_buffer[i]
			* W_HEIGHT / (data->map.sc_x * data->map.height)
			* (data->player.diry) + y);
}

static void		calc_player(t_doom *d)
{
	int			i;
	SDL_Point	pl;

	pl.x = d->player.x * W_WIDTH / (d->map.sc_x * d->map.width);
	pl.y = d->player.y * W_HEIGHT / (d->map.sc_x * d->map.height);
	SDL_SetRenderDrawColor(d->renderer, 0, 0xFF, 0, 0);
	i = -1;
	while (++i < W_WIDTH)
		draw_ray_fov(d, i, pl.x, pl.y);
}

static void		draw_minimap(t_doom *data, int nx)
{
	int			ny;
	SDL_Rect	rect;

	ny = -1;
	rect.h = 2 * W_HEIGHT / (data->map.sc_x * data->map.height);
	rect.w = 2 * W_WIDTH / (data->map.sc_x * data->map.width);
	while (++ny < data->map.height)
	{
		rect.x = nx * W_WIDTH / (data->map.sc_x * data->map.width);
		rect.y = ny * W_HEIGHT / (data->map.sc_x * data->map.height);
		if (data->map.map[nx][ny] == 1 || data->map.map[nx][ny] == 10
			|| data->map.map[nx][ny] == 11 || data->map.map[nx][ny] == 12)
			SDL_SetRenderDrawColor(data->renderer, 100, 24, 24, 20);
		else
			SDL_SetRenderDrawColor(data->renderer, 75, 100, 100, 50);
		SDL_RenderFillRect(data->renderer, &rect);
	}
}

void			minimap(t_doom *data)
{
	int			nx;
	int			ny;

	nx = -1;
	while (++nx < data->map.width)
		draw_minimap(data, nx);
	nx = -1;
	while (++nx < data->map.width)
	{
		ny = -1;
		while (++ny < data->map.height)
		{
			if ((ny + 1) * data->map.width + nx == data->player.pos)
				calc_player(data);
		}
	}
	draw_fps(data);
	object_minimap(data, data->monster);
}
