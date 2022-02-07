/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_sqr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:40:51 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	set_spawner(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = SPAWNER;
		}
	}
}

void	set_objects(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = e->ed.sqr;
		}
	}
}

void	set_win(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	if (e->ed.win_e)
		return ;
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = WIN;
			e->ed.win_e = 1;
			e->ed.win = 0;
		}
	}
}

void	set_player(t_doom *e)
{
	t_point mo;

	SDL_PumpEvents();
	if (e->ed.player_exist)
		return ;
	if (SDL_GetMouseState(&mo.x, &mo.y) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if ((mo.x >= (CUBE_SIZE / 3) && mo.x <= (19 * (CUBE_SIZE / 3) - 1))
				&& (mo.y >= (CUBE_SIZE / 3)
					&& mo.y <= (19 * (CUBE_SIZE / 3) - 1)))
		{
			e->ed.pos.x = mo.x / (CUBE_SIZE / 3);
			e->ed.pos.y = mo.y / (CUBE_SIZE / 3);
			e->ed.map[e->ed.pos.y][e->ed.pos.x] = PLAYER;
			e->ed.player_exist = 1;
			e->ed.player = 0;
		}
	}
}
