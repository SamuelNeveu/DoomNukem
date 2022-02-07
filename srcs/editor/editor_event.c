/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:47:57 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	void		get_editor_events(t_doom *data)
{
	scan_events(data);
	if (data->event.button.button == SDL_BUTTON_LEFT)
		data->key[LCLICK] = data->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
	else if (data->event.button.button == SDL_BUTTON_RIGHT)
		data->key[RCLICK] = data->event.type == SDL_MOUSEBUTTONDOWN ? 1 : 0;
	else if (data->event.button.button == SDL_SCANCODE_TAB)
		data->key[KEY_TAB] = data->event.type == SDL_KEYDOWN ? 1 : 0;
}

void				editor_event(t_doom *data)
{
	while (SDL_PollEvent(&data->event))
	{
		if ((data->event.key.keysym.sym == SDLK_ESCAPE
		&& data->event.type == SDL_KEYDOWN)
		|| data->event.type == SDL_QUIT)
			clean_exit(data, NULL, 1);
		else if (data->event.type == SDL_MOUSEMOTION)
			data->key[MOUSE] = 1;
		else
			get_editor_events(data);
	}
	platform_event(data);
}
