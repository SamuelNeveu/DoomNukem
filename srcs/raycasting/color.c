/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 19:55:08 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:52:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

int					rgb_to_hsv(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

t_rgba				fill_rgb(int c)
{
	t_rgba rgb;

	rgb.r = c / (256 * 256);
	rgb.g = (c / 256) % 256;
	rgb.b = c % 256;
	return (rgb);
}

SDL_Color			ft_hex_to_rgb(int hexa)
{
	SDL_Color color;

	color.r = hexa >> 24;
	color.g = hexa >> 16;
	color.b = hexa >> 8;
	color.a = hexa;
	return (color);
}
