/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_refresh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:10:57 by brpinto           #+#    #+#             */
/*   Updated: 2020/08/01 19:19:09 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	cursor_disp(t_doom *e, int i, int j)
{
	t_point	start;
	t_point	end;

	start.x = (i) * (CUBE_SIZE / 3);
	start.y = (j) * (CUBE_SIZE / 3);
	start.i = CUBE_SIZE / 3;
	end.y = (j + 1) * (CUBE_SIZE / 3);
	end.x = (i) * (CUBE_SIZE / 3);
	draw_sqr(e->renderer, start, end);
}

void	reset(t_doom *e)
{
	int	j;
	int	i;

	j = 0;
	while (j < 20)
	{
		i = 0;
		while (i < 20)
		{
			e->ed.map[j][i] = 0;
			i++;
		}
		j++;
	}
	e->ed.player_exist = 0;
	e->ed.win_e = 0;
}

void	set_color(t_doom *e, int i, int j)
{
	if (e->ed.map[j][i] == FLOOR)
		SDL_SetRenderDrawColor(e->renderer, 0, 0, 0, 255);
	else if (e->ed.map[j][i] == WALL || e->ed.map[j][i] == WALL1
			|| e->ed.map[j][i] == WALL2)
		SDL_SetRenderDrawColor(e->renderer, 0, 255, 0, 255);
	else if (e->ed.map[j][i] == PLAYER)
		SDL_SetRenderDrawColor(e->renderer, 255, 0, 0, 255);
	else if (e->ed.map[j][i] == PLANT)
		SDL_SetRenderDrawColor(e->renderer, 0, 0, 255, 255);
	else if (e->ed.map[j][i] == CAGE)
		SDL_SetRenderDrawColor(e->renderer, 255, 0, 204, 255);
	else if (e->ed.map[j][i] == TABLE)
		SDL_SetRenderDrawColor(e->renderer, 255, 0, 102, 255);
	else if (e->ed.map[j][i] == AMMO)
		SDL_SetRenderDrawColor(e->renderer, 0, 255, 255, 255);
	else if (e->ed.map[j][i] == HEAL)
		SDL_SetRenderDrawColor(e->renderer, 153, 0, 204, 255);
	else if (e->ed.map[j][i] == SPAWNER)
		SDL_SetRenderDrawColor(e->renderer, 102, 255, 153, 255);
	else if (e->ed.map[j][i] == WIN)
		SDL_SetRenderDrawColor(e->renderer, 255, 255, 0, 255);
}

void	refresh_map(t_doom *e)
{
	int i;
	int j;

	j = -1;
	while (++j < (e->ed.map_h))
	{
		i = -1;
		while (++i < (e->ed.map_w))
		{
			set_color(e, i, j);
			cursor_disp(e, i, j);
		}
	}
}
