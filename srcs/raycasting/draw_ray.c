/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:04:10 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:57:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

uint32_t		get_pixel_ray(t_doom *data, int si, int coord[2], t_ray *ray)
{
	uint8_t			*p;
	t_sprite		surface;
	Uint32			pixel;

	surface = data->sprite[si];
	p = (uint8_t *)surface.img->pixels + (int)coord[1] * surface.img->pitch
		+ (int)coord[0] * surface.img->format->BytesPerPixel;
	pixel = (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
	return (fog(data, pixel, ray->perpwalldist));
}

void			draw_wall(t_doom *d, int x, t_ray *ray)
{
	int		y;
	int		dis;
	double	texpos;

	if (ray->wallside == 0)
		ray->wallx = d->player.y + ray->perpwalldist * ray->diry;
	else
		ray->wallx = d->player.x + ray->perpwalldist * ray->dirx;
	ray->wallx = ray->wallx - (int)ray->wallx;
	d->map.depth_buffer[x] = ray->perpwalldist;
	ray->wtx = (int)(ray->wallx * (double)d->sprite[ray->tex].img->w);
	if ((ray->wallside == 0 && ray->dirx > 0)
			|| (ray->wallside == 1 && ray->diry < 0))
		ray->wtx = d->sprite[ray->tex].img->w - ray->wtx;
	y = ray->walltop;
	while (y < ray->wallbot)
	{
		texpos = (y - d->player.pitch - (d->player.posz / ray->perpwalldist));
		dis = texpos * 256 - W_HEIGHT * 128 + ray->height * 128;
		ray->wty = ((dis * d->sprite[ray->tex].img->h)
				/ ray->height) / 256;
		put_pixel(d->screen, x, y,
			get_pixel_ray(d, ray->tex, (int[2]){ray->wtx, ray->wty}, ray));
		y++;
	}
}

void			get_tex(t_ray *ray)
{
	if (!(ray->wallside) && ray->dirx < 0)
		ray->tex = 16;
	else if (!(ray->wallside) && ray->dirx >= 0)
		ray->tex = 17;
	else if (ray->wallside && ray->diry < 0)
		ray->tex = 18;
	else if (ray->wallside && ray->diry >= 0)
		ray->tex = 19;
}
