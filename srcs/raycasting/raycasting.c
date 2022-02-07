/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:46:06 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:47:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static void		perp_height(t_doom *d, t_ray *ray)
{
	if (ray->wallside == 0)
		ray->perpwalldist = (ray->maposx - d->player.x
				+ (1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->perpwalldist = (ray->maposy - d->player.y
				+ (1 - ray->stepy) / 2) / ray->diry;
	ray->height = (int)(W_HEIGHT / ray->perpwalldist);
	ray->walltop = (int)(-ray->height / 2 + W_HEIGHT / 2 + d->player.pitch
		+ (d->player.posz / ray->perpwalldist));
	if (ray->walltop < 0)
		ray->walltop = 0;
	ray->wallbot = (int)(ray->height / 2 + W_HEIGHT / 2 + d->player.pitch
		+ (d->player.posz / ray->perpwalldist));
	if (ray->wallbot >= W_HEIGHT)
		ray->wallbot = W_HEIGHT - 1;
}

static void		hitwall(t_doom *data, t_ray *ray)
{
	ray->wallhit = 0;
	while (ray->wallhit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->maposx += ray->stepx;
			ray->wallside = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->maposy += ray->stepy;
			ray->wallside = 1;
		}
		if (data->map.map[ray->maposx][ray->maposy] == WALL
		|| data->map.map[ray->maposx][ray->maposy] == WALL1
		|| data->map.map[ray->maposx][ray->maposy] == WALL2)
			ray->wallhit = 1;
		wall_detect(data, ray);
	}
	perp_height(data, ray);
}

static void		get_side(t_doom *data, t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->sidedistx = (data->player.x - ray->maposx)
			* ray->deltadistx;
		ray->stepx = -1;
	}
	else
	{
		ray->sidedistx = (ray->maposx + 1.0 - data->player.x)
			* ray->deltadistx;
		ray->stepx = 1;
	}
	if (ray->diry < 0)
	{
		ray->sidedisty = (data->player.y - ray->maposy)
			* ray->deltadisty;
		ray->stepy = -1;
	}
	else
	{
		ray->sidedisty = (ray->maposy + 1.0 - data->player.y)
			* ray->deltadisty;
		ray->stepy = 1;
	}
}

static void		ray_calcul(t_doom *data, int x, t_ray *ray)
{
	ray->camera = 2 * x / (double)W_WIDTH - 1;
	ray->dirx = data->player.dirx + data->player.planex * ray->camera;
	ray->diry = data->player.diry + data->player.planey * ray->camera;
	ray->deltadistx = sqrt(1 + (ray->diry * ray->diry)
			/ (ray->dirx * ray->dirx));
	ray->deltadisty = sqrt(1 + (ray->dirx * ray->dirx)
			/ (ray->diry * ray->diry));
	ray->maposx = (int)data->player.x;
	ray->maposy = (int)data->player.y;
	get_side(data, ray);
}

void			*raycasting(void *thread)
{
	t_thread	*t;
	t_doom		*data;
	t_ray		ray;

	t = (t_thread*)thread;
	data = t->env;
	while (++t->i < t->end)
	{
		ray_calcul(data, t->i, &ray);
		hitwall(data, &ray);
		draw_wall(data, t->i, &ray);
		draw_floor_ceilling(data, t->i, &ray);
	}
	pthread_exit(NULL);
}
