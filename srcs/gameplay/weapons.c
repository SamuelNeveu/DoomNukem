/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Horizontally centers the weapon sprite.
*/

static void		center_hor(t_doom *data, int i)
{
	int w_id;

	w_id = data->player.weapon;
	data->player.wdata[i].hor_off = (data->player.wdata[i].width / 2);
	if (w_id == WP_PISTOL)
		data->player.wdata[i].hor_off -= 30;
	else if (w_id == WP_SMG)
		data->player.wdata[i].hor_off -= 29;
}

/*
** Vertically offsets the weapon sprite.
*/

static void		off_vert(t_doom *data, int w_id)
{
	double percentage;

	if (data->player.reloading && w_id != WP_FISTS)
	{
		percentage = (double)data->player.gbl_delay
			/ (double)data->player.wdata[w_id].clip_rld;
		if (percentage >= 0.75)
			percentage = 1 - percentage;
		else if (percentage >= 0.25)
			percentage = 1;
	}
	else
		percentage = 0;
	data->player.wdata[w_id].vert_off = data->player.wdata[w_id].height
	- percentage * 1500 - 10;
}

/*
** Bobs the weapon up and down when standing still, left and right when moving.
*/

static void		bobbing(t_doom *data, int w_id)
{
	static double	i = 0.0;
	static int		sign = 1;
	float			bobbing_speed;

	if (data->player.gbl_delay <= 0)
	{
		bobbing_speed = 0.02;
		if (data->key[KEY_W] || data->key[KEY_A]
		|| data->key[KEY_S] || data->key[KEY_D])
			bobbing_speed = 0.15;
		i = i + bobbing_speed * sign;
		if (i <= -1.2 || i > 1.2)
		{
			i = 1.2 * sign;
			sign *= -1;
		}
	}
	if (data->key[KEY_W] || data->key[KEY_A]
	|| data->key[KEY_S] || data->key[KEY_D])
		data->player.wdata[w_id].hor_off -= sin(i * M_PI_2) * 10;
	data->player.wdata[w_id].vert_off -= cos(i * M_PI_2) * 10;
}

/*
** Gets or calculates all necessary variables to draw the weapon.
*/

static void		obtain_weapon_data(t_doom *data)
{
	int			w_id;
	int			si;
	SDL_Surface	*img;

	w_id = data->player.weapon;
	si = get_weapon_skin(data);
	data->player.wdata[w_id].si = si;
	img = data->wp_sprite[si].img;
	data->player.wdata[w_id].zpixel = get_pxl_wp(data, si, 0, 0);
	data->player.wdata[w_id].height = img->h * 2;
	data->player.wdata[w_id].width = img->w * 2;
	center_hor(data, w_id);
	off_vert(data, w_id);
	bobbing(data, w_id);
}

/*
** Draws the weapon and ignores a certain pixel color.
*/

void			weapons(t_doom *data)
{
	int			i;
	int			x;
	int			y;
	uint32_t	pixel;

	i = data->player.weapon;
	obtain_weapon_data(data);
	x = -1;
	while (++x < data->player.wdata[i].width)
	{
		y = -1;
		while (++y < data->player.wdata[i].height)
		{
			pixel = get_pxl_wp(data, data->player.wdata[i].si,
					x / (data->player.wdata[i].width),
					y / (data->player.wdata[i].height));
			if (pixel == data->player.wdata[i].zpixel)
				continue ;
			put_pixel(data->screen,
					(W_WIDTH / 2) - data->player.wdata[i].hor_off + x,
					(W_HEIGHT - data->player.wdata[i].vert_off) + y, pixel);
		}
	}
}
