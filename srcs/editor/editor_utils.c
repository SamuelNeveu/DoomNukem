/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:23:37 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/30 15:02:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_string	create_texture(t_doom *e, t_point pos, t_string to_copy)
{
	SDL_Color	color;
	SDL_Surface	*surf;
	t_string	string;

	string = to_copy;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;
	surf = TTF_RenderText_Solid(e->font.police2, string.name, color);
	string.text = SDL_CreateTextureFromSurface(e->renderer, surf);
	string.tex_h = 0;
	string.tex_w = 0;
	SDL_QueryTexture(string.text, NULL, NULL, &string.tex_w, &string.tex_h);
	string.rect.x = pos.x;
	string.rect.y = pos.y;
	string.rect.w = string.tex_w;
	string.rect.h = string.tex_h;
	SDL_FreeSurface(surf);
	return (string);
}

int			button_collide(t_doom *e, t_point pos, t_point size)
{
	if ((e->mouse.x >= pos.x && e->mouse.x <= (pos.x + size.x))
			&& (e->mouse.y >= pos.y && e->mouse.y <= (pos.y + size.y)))
		return (1);
	return (0);
}

/*
**void		obj_add(t_obj **link, t_obj *new)
**  {
**if (link)
**new->next = *link;
***link = new;
**}
*/

/*
** void	draw_sqr(SDL_Surface *surface, t_point start, t_point end,
**uint32_t color)
**{
*/

void		draw_sqr(SDL_Renderer *renderer, t_point start, t_point end)
{
	int i;

	i = 0;
	while (i <= start.i)
	{
		draw_line(renderer, start, end);
		i++;
		start.x++;
		end.x++;
	}
}

void		check_d_err(t_draw_ed *ray)
{
	if (ray->d_e2 > -ray->d.x)
	{
		ray->d_err -= ray->d.y;
		ray->curr.x += ray->d_s.x;
	}
	if (ray->d_e2 < ray->d.y)
	{
		ray->d_err += ray->d.x;
		ray->curr.y += ray->d_s.y;
	}
}

/*
**void		draw_line(SDL_Surface *surface, t_point start,
**t_point end, uint32_t color)
**{
*/

void		draw_line(SDL_Renderer *renderer, t_point start, t_point end)
{
	t_draw_ed		ray;

	ray.d.x = abs(end.x - start.x);
	ray.d_s.x = (start.x < end.x ? 1 : -1);
	ray.d.y = abs(end.y - start.y);
	ray.d_s.y = (start.y < end.y ? 1 : -1);
	ray.d_err = (ray.d.x > ray.d.y ? ray.d.x : -ray.d.y) / 2;
	ray.curr.x = start.x;
	ray.curr.y = start.y;
	while (1)
	{
		SDL_RenderDrawPoint(renderer, ray.curr.x, ray.curr.y);
		if (ray.curr.x == end.x && ray.curr.y == end.y)
			break ;
		ray.d_e2 = ray.d_err;
		check_d_err(&ray);
	}
}
