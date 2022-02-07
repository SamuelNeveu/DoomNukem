/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:39:47 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/30 15:10:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
**void		draw_rows(t_doom *e, uint32_t color)
**{
*/

static	void	draw_rows(t_doom *e)
{
	int		j;
	t_point	start;
	t_point	end;

	start.x = CUBE_SIZE / 3;
	start.y = CUBE_SIZE / 3;
	end.y = CUBE_SIZE / 3;
	end.x = (e->ed.map_w - 1) * (CUBE_SIZE / 3);
	j = 0;
	while (j < (e->ed.map_h - 1))
	{
		SDL_SetRenderDrawColor(e->renderer, 255, 255, 255, 255);
		draw_line(e->renderer, start, end);
		start.y += CUBE_SIZE / 3;
		end.y += CUBE_SIZE / 3;
		j++;
	}
}

/*
**static void		draw_cols(t_doom *e, uint32_t color)
**{
*/

static	void	draw_cols(t_doom *e)
{
	int		i;
	t_point	start;
	t_point	end;

	start.x = CUBE_SIZE / 3;
	start.y = CUBE_SIZE / 3;
	end.x = CUBE_SIZE / 3;
	end.y = (e->ed.map_h - 1) * (CUBE_SIZE / 3);
	i = 0;
	while (i < (e->ed.map_w - 1))
	{
		SDL_SetRenderDrawColor(e->renderer, 255, 255, 255, 255);
		draw_line(e->renderer, start, end);
		start.x += CUBE_SIZE / 3;
		end.x += CUBE_SIZE / 3;
		i++;
	}
}

/*
**void			draw_grid(t_doom *e, uint32_t color)
**{
**draw_cols(e, color);
**draw_rows(e, color);
**}
*/

void			draw_grid(t_doom *e)
{
	draw_cols(e);
	draw_rows(e);
}
