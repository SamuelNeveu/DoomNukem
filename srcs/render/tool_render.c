/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:30:19 by bebosson          #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	set_write_to_screen(t_doom *data, SDL_Rect rect, int c, char *str)
{
	SDL_Surface	*surf_write;
	SDL_Texture *text_write;

	surf_write = TTF_RenderText_Solid(data->font.policep, str,
		ft_hex_to_rgb(c));
	text_write = SDL_CreateTextureFromSurface(data->renderer, surf_write);
	SDL_QueryTexture(text_write, 0, 0, &(rect.w), &(rect.h));
	SDL_RenderCopy(data->renderer, text_write, NULL, &rect);
	SDL_FreeSurface(surf_write);
	SDL_DestroyTexture(text_write);
}

void	set_rect_to_screen(t_doom *data, SDL_Rect *rect, int c)
{
	int a;

	a = 0xff;
	SDL_SetRenderDrawColor(data->renderer, c >> 16 & a, c >> 8 & a, c & a, 100);
	SDL_RenderFillRect(data->renderer, rect);
}

void	add_sc_x(t_doom *data)
{
	if (data->event.key.keysym.sym == SDLK_b)
	{
		data->key[KEY_B] = data->event.type == SDL_KEYDOWN ? 1 : 0;
		if (data->key[KEY_B] == 1 && data->map.sc_x < 5)
			data->map.sc_x++;
	}
	else if (data->event.key.keysym.sym == SDLK_n)
	{
		data->key[KEY_N] = data->event.type == SDL_KEYDOWN ? 1 : 0;
		if (data->key[KEY_N] == 1 && data->map.sc_x > 2)
			data->map.sc_x--;
	}
}
