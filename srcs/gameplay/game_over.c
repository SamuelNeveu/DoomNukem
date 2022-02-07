/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:48:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/30 15:04:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Plays the Game Over sound effect and displays the end screen.
*/

void			game_over(t_doom *data)
{
	play_sound(data, data->sound.playerdeath, 5);
	data->player.platform = END;
	data->player.game_over = 1;
}

void			game_win(t_doom *data)
{
	play_sound(data, data->sound.playerspawn, 5);
	data->player.platform = END;
	data->player.game_over = 0;
}

/*
** Sets the end portal to its location.
*/

void			set_end_pt(t_doom *d, t_object *list, int i, int j)
{
	d->end.y = j;
	d->end.x = i;
	list->x = i + 0.5;
	list->y = j + 0.5;
	list->type = d->map.map[i][j];
	list->si = list->type;
	list->i = list->x + d->map.width * list->y;
	list->sprite = d->sprite[20];
	list->dead = 0;
	d->map.map[i][j] = 0;
}

/*
** Displays the end screen, be it a victory or a defeat.
*/

void			game_ending(t_doom *data)
{
	SDL_FillRect(data->screen, NULL, 0x00000000);
	if (SDL_BlitSurface(data->menu.menu2, NULL, data->screen, NULL) == -1)
		ft_putstr("error blitsurface");
	data->menu.textpos.x = (data->screen->w / 2) - (data->menu.text->w / 2);
	data->menu.textpos.y = (data->screen->h / 2) - (data->menu.text->h / 2);
	if (data->player.game_over)
		writeonscreen(data, "GAME-OVER", data->menu.textcolor);
	if (!data->player.game_over)
		writeonscreen(data, "YOU WIN", data->menu.textcolor);
	data->menu.textpos.x = (data->screen->w / 2) - (data->menu.text->w / 2);
	data->menu.textpos.y = (data->screen->h / 1.5) - (data->menu.text->h / 1.5);
	writeonscreen(data, "ESC TO RAGEQUIT", data->menu.textcolor);
}

void			end_screen(t_doom *data)
{
	SDL_FlushEvent(SDL_KEYDOWN);
	SDL_FlushEvent(SDL_MOUSEMOTION);
	while (SDL_PollEvent(&data->event))
		if ((data->event.key.keysym.sym == SDLK_SPACE)
				|| data->event.window.event == SDL_WINDOWEVENT_CLOSE
				|| data->event.key.keysym.sym == SDLK_ESCAPE)
			clean_exit(data, "", 1);
}
