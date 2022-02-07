/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 22:04:08 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/31 21:02:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void			sdl_render(t_doom *data)
{
	int				i;
	unsigned int	*pixels;

	data->window = SDL_CreateTextureFromSurface(data->renderer, data->screen);
	SDL_RenderCopy(data->renderer, data->window, NULL, NULL);
	SDL_RenderPresent(data->renderer);
	SDL_DestroyTexture(data->window);
	pixels = (unsigned int *)data->screen->pixels;
	i = -1;
	while (++i < W_WIDTH * W_HEIGHT)
		pixels[i] = (0 | 0 << 8 | 0 << 16 | 255 << 24);
}
