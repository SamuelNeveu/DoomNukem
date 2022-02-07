/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:26:54 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 18:42:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static int		checktexture(t_doom *d, t_ray *ray)
{
	int t;
	int c;

	c = 0;
	t = 0;
	if (d->floorstyle == 0)
		t = 1;
	else
	{
		if (d->floorstyle == 2)
			c = ((int)(ray->currentfloorx + ray->currentfloory)) % 2;
		else
			c = ((int)ray->currentfloorx + (int)ray->currentfloory) % 2;
		if (c == 0)
			t = 0;
		else
			t = 1;
	}
	return (t);
}

static void		pxl_add(t_doom *d, int coord[2], int tx, t_ray *ray)
{
	int tex;

	if (tx == 1)
		tex = 0;
	else
		tex = checktexture(d, ray);
	ray->wtx = (int)(ray->currentfloorx * d->sprite[tex].img->w)
		% d->sprite[tex].img->w;
	ray->wty = (int)(ray->currentfloory * d->sprite[tex].img->h)
		% d->sprite[tex].img->h;
	put_pixel(d->screen, coord[0], coord[1],
		get_pixel_floor(d, tex, (int[2]){ray->wtx, ray->wty}, ray));
}

static void		floor_calcul2(t_doom *d, int x, int y, t_ray *ray)
{
	y = ray->wallbot - 1;
	while (++y < W_HEIGHT)
	{
		ray->distcurrent = (W_HEIGHT + (2 * d->player.posz))
			/ (2.0 * (y - d->player.pitch) - W_HEIGHT);
		ray->weight = ray->distcurrent / ray->distwall;
		ray->currentfloorx = ray->weight * ray->floorwallx
			+ (1.0 - ray->weight) * d->player.x;
		ray->currentfloory = ray->weight * ray->floorwally
			+ (1.0 - ray->weight) * d->player.y;
		pxl_add(d, (int[2]){x, y}, 0, ray);
	}
}

static void		floor_calcul(t_doom *d, int x, t_ray *ray)
{
	int y;

	ray->distwall = ray->perpwalldist;
	if (ray->wallbot < 0)
		ray->wallbot = W_HEIGHT;
	y = -1;
	while (++y < ray->walltop)
	{
		ray->distcurrent = (W_HEIGHT - (2 * d->player.posz))
			/ (W_HEIGHT - 2.0 * (y - d->player.pitch));
		ray->weight = ray->distcurrent / ray->distwall;
		ray->currentfloorx = ray->weight * ray->floorwallx
			+ (1.0 - ray->weight) * d->player.x;
		ray->currentfloory = ray->weight * ray->floorwally
			+ (1.0 - ray->weight) * d->player.y;
		pxl_add(d, (int[2]){x, y}, 1, ray);
	}
	floor_calcul2(d, x, y, ray);
}

void			draw_floor_ceilling(t_doom *d, int x, t_ray *ray)
{
	if (ray->wallside == 0)
	{
		ray->floorwallx = ray->maposx;
		ray->floorwally = ray->maposy + ray->wallx;
		if (ray->dirx < 0)
			ray->floorwallx += 1.0;
	}
	else
	{
		ray->floorwallx = ray->maposx + ray->wallx;
		ray->floorwally = ray->maposy;
		if (ray->diry < 0)
			ray->floorwally += 1.0;
	}
	floor_calcul(d, x, ray);
}
