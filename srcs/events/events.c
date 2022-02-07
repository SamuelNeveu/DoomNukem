/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:14:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Scans most keyboard events.
*/

void			scan_events(t_doom *data)
{
	if (data->event.key.keysym.scancode == SDL_SCANCODE_W)
		data->key[KEY_W] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_A)
		data->key[KEY_A] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_S)
		data->key[KEY_S] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_D)
		data->key[KEY_D] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_J)
		data->key[KEY_J] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_R)
		data->key[KEY_R] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_Q)
		data->key[KEY_Q] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_E)
		data->key[KEY_E] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		data->key[KEY_SPACE] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_LCTRL)
		data->key[KEY_LCTRL] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_TAB)
		data->key[KEY_TAB] = data->event.type == SDL_KEYDOWN ? 1 : 0;
}

/*
** Scans some weapon events.
*/

static void		weapon_events(t_doom *data)
{
	if (data->event.key.keysym.scancode == SDL_SCANCODE_1)
		data->key[KEY_NUM1] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_2)
		data->key[KEY_NUM2] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_3)
		data->key[KEY_NUM3] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_4)
		data->key[KEY_NUM4] = data->event.type == SDL_KEYDOWN ? 1 : 0;
	else if (data->event.key.keysym.scancode == SDL_SCANCODE_5)
		data->key[KEY_NUM5] = data->event.type == SDL_KEYDOWN ? 1 : 0;
}

/*
** Regroups events from previous functions and handle a few more events.
*/

static void		get_events(t_doom *data)
{
	scan_events(data);
	weapon_events(data);
	if (data->event.button.button == SDL_BUTTON_LEFT)
		data->key[LCLICK] = data->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
	else if (data->event.button.button == SDL_BUTTON_RIGHT)
		data->key[RCLICK] = data->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
	else if (data->event.key.keysym.sym == SDLK_m)
	{
		if (data->event.type == SDL_KEYDOWN)
			data->key[KEY_M] = data->key[KEY_M] ? 0 : 1;
	}
	else if (data->event.key.keysym.sym == SDLK_y
		&& data->event.type == SDL_KEYDOWN)
		switch_floor(data);
	else if (data->event.key.keysym.sym == SDLK_f
		&& data->event.type == SDL_KEYDOWN)
		switch_fog(data);
}

/*
** Regroups all other events and handles some more before sending
** the results to functions using them.
*/

void			events(t_doom *data)
{
	while (SDL_PollEvent(&data->event))
	{
		if ((data->event.key.keysym.sym == SDLK_ESCAPE
		&& data->event.type == SDL_KEYDOWN)
		|| data->event.type == SDL_QUIT)
			clean_exit(data, NULL, 1);
		else if (data->event.key.keysym.sym == SDLK_b
		|| data->event.key.keysym.sym == SDLK_n)
			add_sc_x(data);
		else if (data->event.type == SDL_KEYDOWN
			&& data->event.key.keysym.sym == SDLK_p)
			data->player.platform = PAUSE;
		else if (data->event.key.keysym.sym == SDLK_LSHIFT)
			data->key[KEY_SHIFT] = data->event.type == SDL_KEYDOWN ? 1 : 0;
		else if (data->event.type == SDL_MOUSEMOTION)
			data->key[MOUSE] = 1;
		else
			get_events(data);
	}
	movements(data);
	platform_event(data);
	swap_weapons(data);
	reload_weapon(data);
}
