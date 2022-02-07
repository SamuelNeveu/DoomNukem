/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:07:10 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/30 15:06:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void			help_pause(t_doom *data)
{
	data->key[KEY_P] = 0;
	play_sound(data, data->sound.playerspawn, 1);
}

uint32_t		get_pixel(t_doom *data, int si, float samplex, float sampley)
{
	int				sx;
	int				sy;
	uint8_t			*p;
	t_sprite		surface;

	surface = data->sprite[si];
	sx = samplex * surface.img->w;
	sy = sampley * surface.img->h;
	p = (uint8_t *)surface.img->pixels + sy * surface.img->pitch
		+ sx * surface.img->format->BytesPerPixel;
	return (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
}

uint32_t		get_pixel_obj(t_object *l, int tx, int ty)
{
	uint8_t			*p;
	t_sprite		surface;

	surface = l->sprite;
	p = (uint8_t *)surface.img->pixels + ty * surface.img->pitch
		+ tx * surface.img->format->BytesPerPixel;
	return (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
}

uint32_t		get_pixel_floor(t_doom *data, int si, int coord[2], t_ray *ray)
{
	uint8_t			*p;
	t_sprite		surface;
	uint32_t		pixel;

	surface = data->sprite[si];
	p = (uint8_t *)surface.img->pixels + coord[1] * surface.img->pitch
		+ coord[0] * surface.img->format->BytesPerPixel;
	pixel = (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
	return (fog(data, pixel, ray->distcurrent));
}

SDL_Surface		*new_surface(int w, int h)
{
	Uint32	color[4];

	color[0] = 0x000000ff;
	color[1] = 0x0000ff00;
	color[2] = 0x00ff0000;
	color[3] = 0xff000000;
	return (SDL_CreateRGBSurface(0, w, h, 32,
				color[0], color[1], color[2], color[3]));
}
