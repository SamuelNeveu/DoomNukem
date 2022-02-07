/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:05:22 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:14:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Swaps to the next weapon with a right click,
** or to the fists if the end has been reached.
*/

void			change_weapon(t_doom *data)
{
	if (data->player.gbl_delay <= 0 && data->key[RCLICK])
	{
		if (data->player.weapon < WP_NB)
		{
			++data->player.weapon;
			if (data->player.weapon == WP_NB)
			{
				data->player.weapon = 0;
				play_sound(data, data->sound.hand, 6);
			}
			else
				play_sound(data, data->sound.switchgun, 6);
		}
	}
	data->key[RCLICK] = 0;
	SDL_FlushEvent(SDL_MOUSEBUTTONDOWN);
}

/*
** Handles the player's view with the mouse.
*/

void			mouse(t_doom *data, Sint16 xrel, int dir)
{
	double	olddirx;
	double	oldplanex;
	double	angle;

	angle = xrel * M_PI / 180 * dir;
	olddirx = data->player.dirx;
	data->player.dirx = (data->player.dirx * cos(angle))
		- (data->player.diry * sin(angle));
	data->player.diry = (olddirx * sin(angle))
		+ (data->player.diry * cos(angle));
	oldplanex = data->player.planex;
	data->player.planex = (oldplanex * cos(angle))
		- (data->player.planey * sin(angle));
	data->player.planey = (oldplanex * sin(angle))
		+ (data->player.planey * cos(angle));
	data->player.pitch -= data->mouse.yrel;
	data->player.pitch < -350 ? data->player.pitch = -350 : 0;
	data->player.pitch > 750 ? data->player.pitch = 750 : 0;
}

/*
** Handles player's view and resets mouse position if it exits the screen.
*/

void			mouse_motion(t_doom *data)
{
	mouse(data, data->mouse.xrel, 1);
	if (abs(data->mouse.xrel) > W_WIDTH / 2
	|| data->mouse.x > data->wx + W_WIDTH
	|| data->mouse.x < data->wx
	|| data->mouse.y > data->wy + W_HEIGHT
	|| data->mouse.y < data->wy)
		SDL_WarpMouseGlobal(data->wx + W_WIDTH / 2,
			data->wy + W_HEIGHT / 2);
}

/*
** Functions that use the mouse through clicking or moving.
*/

void			mouse_events(t_doom *data)
{
	fire_weapon(data);
	if (data->key[RCLICK])
		change_weapon(data);
	if (data->key[MOUSE] == 1)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_GetGlobalMouseState(&(data->mouse.x), &(data->mouse.y));
		SDL_GetRelativeMouseState(&(data->mouse.xrel), &(data->mouse.yrel));
		mouse_motion(data);
		SDL_FlushEvent(SDL_MOUSEMOTION);
		data->key[MOUSE] = 0;
	}
}
