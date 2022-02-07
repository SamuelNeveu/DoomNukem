/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 22:13:07 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

/*
** Initializes fonts that will be used by the program.
*/

void	open_font(t_doom *data)
{
	if (TTF_Init() == -1)
		clean_exit(data, (char*)IMG_GetError(), 0);
	if (!(data->font.police = TTF_OpenFont("img/police/AmazDooMLeft.ttf", 200)))
		clean_exit(data, (char *)TTF_GetError(), 0);
	if (!(data->font.police2 = TTF_OpenFont("img/police/bit.ttf", 20)))
		clean_exit(data, "doom-nukem: error police2  TTF_OpenFont", 0);
	if (!(data->font.police3 = TTF_OpenFont("img/police/bit.ttf", 8)))
		clean_exit(data, "doom-nukem: error police3 TTF_OpenFont", 0);
}

/*
** Initializes window, main menu, fonts, audio and forge variables.
*/

void	init_sdl(t_doom *data)
{
	Uint32	color[4];

	color[0] = 0x000000ff;
	color[1] = 0x0000ff00;
	color[2] = 0x00ff0000;
	color[3] = 0xff000000;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		clean_exit(data, "SDL_Init fail", 0);
	if (!(data->pwindow = SDL_CreateWindow("DooM NukeM",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					W_WIDTH, W_HEIGHT, 0)))
		clean_exit(data, "windows creation failed", 0);
	if (!(data->renderer = SDL_CreateRenderer(data->pwindow
		, -1, SDL_RENDERER_ACCELERATED)))
		clean_exit(data, "create renderer fail", 0);
	data->screen = SDL_CreateRGBSurface(0, W_WIDTH, W_HEIGHT, 32,
		color[0], color[1], color[2], color[3]);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		clean_exit(data, "doom-nukem: Mix_OpenAudio failed", 0);
	else
		audio_init(data);
	open_font(data);
	SDL_ShowCursor(SDL_DISABLE);
}
