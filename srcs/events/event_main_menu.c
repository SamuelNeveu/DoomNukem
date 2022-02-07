/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_main_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 18:16:11 by apons             #+#    #+#             */
/*   Updated: 2020/07/31 20:19:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Handles the main menu's left click event.
*/

static void	event_mm_left_click(t_doom *data)
{
	SDL_GetMouseState(&data->clicks.x, &data->clicks.y);
	if (data->clicks.y > data->menu.button1pos.y
		&& data->clicks.y <= data->menu.button1pos.y + data->menu.button->h
		&& data->clicks.x > data->menu.button1pos.x
		&& data->clicks.x <= data->menu.button1pos.x + data->menu.button->w)
	{
		if (data->player.platform == MENU)
			data->player.platform = GAME;
		else if (data->player.platform == PAUSE)
			data->player.platform = GAME;
		play_music(data, data->sound.ingmusic);
	}
	else if (data->clicks.y > data->menu.button2pos.y
		&& data->clicks.y <= data->menu.button2pos.y + data->menu.button->h
		&& data->clicks.x > data->menu.button2pos.x
		&& data->clicks.x <= data->menu.button2pos.x + data->menu.button->w)
	{
		if (data->player.platform == MENU)
			data->player.platform = FORGE;
		play_music(data, data->sound.ingmusic);
	}
	data->key[LCLICK] = 0;
	data->key[RCLICK] = 0;
}

/*
** Handles the main menu's events.
*/

void		event_main_menu(t_doom *data)
{
	while (SDL_PollEvent(&data->event))
	{
		if ((data->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE
			&& data->event.type == SDL_KEYDOWN)
			|| data->event.type == SDL_QUIT)
			clean_exit(data, "END OF GAME\n", 1);
		if (data->event.button.button == SDL_BUTTON_LEFT)
			data->key[LCLICK] = data->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
	}
	if (data->key[LCLICK])
		event_mm_left_click(data);
}
