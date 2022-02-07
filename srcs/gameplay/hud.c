/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 15:35:06 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Draws part of the HUD depending on given stat_id (21 or 22).
** Can also be used with any other ID but undetermined things can happen.
*/

void			draw_stat(t_doom *data, int stat_id, int s_x, int s_y)
{
	int			x;
	int			y;
	uint32_t	pixel;

	x = -1;
	while (++x < data->sprite[stat_id].img->w)
	{
		y = -1;
		while (++y < data->sprite[stat_id].img->h)
		{
			pixel = get_pixel(data, stat_id,
				(float)x / (float)data->sprite[stat_id].img->w,
				(float)y / (float)data->sprite[stat_id].img->h);
			put_pixel(data->screen, s_x + x, s_y + y, pixel);
		}
	}
}

/*
**	Gives color according to remaining health. For each Red, Green, Blue part :
**		color = percentage * color_start + (1 - percentage) * color_end
**	Bits of the formula are not written if they don't influence the result.
*/

static	void	grad_color(t_doom *data)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	percentage = (float)data->player.health / (float)data->player.health_max;
	red = percentage * 30.0 + (1.0 - percentage) * 200.0;
	green = percentage * 200.0;
	blue = percentage * 35.0;
	SDL_SetRenderDrawColor(data->renderer, red, green, blue, 100);
}

/*
** Draws the health bar inside the stat bar.
*/

void			health(t_doom *data)
{
	SDL_Rect	rect;

	rect = (SDL_Rect){15, W_HEIGHT - 45,
		300 * data->player.health / data->player.health_max, 30};
	grad_color(data);
	SDL_RenderFillRect(data->renderer, &rect);
}

/*
** Draws the crosshair in the middle of the screen.
*/

void			cursor(t_doom *data)
{
	SDL_SetRenderDrawColor(data->renderer, 255, 0, 0, 100);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2 - 15, W_HEIGHT / 2,
			W_WIDTH / 2 + 15, W_HEIGHT / 2);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2, W_HEIGHT / 2 - 15,
			W_WIDTH / 2, W_HEIGHT / 2 + 15);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2 - 15, W_HEIGHT / 2 - 1,
			W_WIDTH / 2 + 15, W_HEIGHT / 2 - 1);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2 - 1, W_HEIGHT / 2 - 15,
			W_WIDTH / 2 - 1, W_HEIGHT / 2 + 15);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2 - 15, W_HEIGHT / 2 + 1,
			W_WIDTH / 2 + 15, W_HEIGHT / 2 + 1);
	SDL_RenderDrawLine(data->renderer,
			W_WIDTH / 2 + 1, W_HEIGHT / 2 - 15,
			W_WIDTH / 2 + 1, W_HEIGHT / 2 + 15);
}
