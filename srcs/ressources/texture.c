/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:17:01 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 21:03:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void			sprites_textures(t_doom *data)
{
	if (!(data->sprite[16].img = SDL_LoadBMP("img/textures/wall.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[17].img = SDL_LoadBMP("img/textures/unicorn.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[18].img = SDL_LoadBMP("img/textures/evil-eye.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[19].img = SDL_LoadBMP("img/textures/stone.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[1].img = SDL_LoadBMP("img/textures/stone.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[0].img = SDL_LoadBMP("img/textures/ceilling.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[2].img = SDL_LoadBMP("img/maze.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
}

void			sprites_items(t_doom *data)
{
	if (!(data->sp_items[0].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[1].img = SDL_LoadBMP("img/ammobox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[2].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[3].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[4].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[5].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
	if (!(data->sp_items[6].img = SDL_LoadBMP("img/healbox.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error\n", 0);
}
