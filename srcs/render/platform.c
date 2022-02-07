/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:29:50 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/31 21:00:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void	menu_start(void *data)
{
	t_doom *w;

	w = (t_doom *)data;
	SDL_ShowCursor(SDL_ENABLE);
	main_menu(w);
	event_main_menu(w);
	sdl_render(w);
}

void	menu_pause(void *data)
{
	t_doom *w;

	w = (t_doom *)data;
	SDL_ShowCursor(SDL_ENABLE);
	pause_menu(w);
	event_main_menu(w);
	sdl_render(w);
}

void	gameplay(void *data)
{
	t_doom *w;

	w = (t_doom *)data;
	SDL_ShowCursor(SDL_DISABLE);
	w->global_time = SDL_GetTicks();
	display(w);
	events(w);
}

void	game_end(void *data)
{
	t_doom *d;

	d = (t_doom *)data;
	SDL_ShowCursor(SDL_ENABLE);
	game_ending(d);
	end_screen(d);
	sdl_render(d);
}

void	forge(void *data)
{
	t_doom *w;

	w = (t_doom *)data;
	SDL_ShowCursor(SDL_ENABLE);
	editor_event(w);
	editor(w);
	SDL_RenderPresent(w->renderer);
	SDL_SetRenderDrawColor(w->renderer, 0, 0, 0, 0);
	SDL_RenderClear(w->renderer);
}
