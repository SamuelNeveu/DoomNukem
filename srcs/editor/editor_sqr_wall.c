/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sqr_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:04:30 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	set_wall(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	e->ed.erase = 0;
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = e->ed.wall;
		}
	}
}

void	set_floor(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			if (e->ed.map[e->ed.pos.y][e->ed.pos.x] == PLAYER)
				e->ed.player_exist = 0;
			if (e->ed.map[e->ed.pos.y][e->ed.pos.x] == WIN)
				e->ed.win_e = 0;
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = FLOOR;
		}
	}
}
