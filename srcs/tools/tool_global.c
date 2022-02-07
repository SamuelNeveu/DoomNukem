/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:50:05 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 22:56:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *current;

	current = *alst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

/*
** Checks if any weapon sprite load has failed or not and exits the program
** if necessary.
*/

void		check_sprites_weapons(t_doom *data)
{
	int i;

	i = WPS_NB;
	while (--i >= 0)
	{
		if (!data->wp_sprite[i].img)
			clean_exit(data, "doom-nukem: load_sprites error", 0);
	}
}

/*
** Gets the required pixel of the weapon
*/

uint32_t	get_pxl_wp(t_doom *data, int si, float samplex, float sampley)
{
	int				sx;
	int				sy;
	uint8_t			*p;
	t_sprite		surface;

	surface = data->wp_sprite[si];
	sx = samplex * surface.img->w;
	sy = sampley * surface.img->h;
	p = (uint8_t *)surface.img->pixels + sy * surface.img->pitch
		+ sx * surface.img->format->BytesPerPixel;
	return (p[2] | p[1] << 8 | p[0] << 16 | 255 << 24);
}

void		get_list_bis(t_doom *d, int i, int j, t_object *list)
{
	if (d->map.map[i][j] == 14)
		set_end_pt(d, list, i, j);
	else if (d->map.map[i][j] >= 15 && d->map.map[i][j] <= 16)
		help_get_list_items(d, list, i, j);
	else
		help_get_list(d, list, i, j);
}

void		wall_detect(t_doom *d, t_ray *ray)
{
	if (d->map.map[ray->maposx][ray->maposy] == 1)
	{
		ray->tex = 16;
		ray->wallhit = 1;
	}
	else if (d->map.map[ray->maposx][ray->maposy] == 10)
	{
		ray->tex = 17;
		ray->wallhit = 1;
	}
	else if (d->map.map[ray->maposx][ray->maposy] == 11)
	{
		ray->tex = 18;
		ray->wallhit = 1;
	}
	else if (d->map.map[ray->maposx][ray->maposy] == 12)
	{
		ray->tex = 19;
		ray->wallhit = 1;
	}
}

/*
**void after_main() __attribute__((destructor));
**void after_main()
**{
**	while (1);
**}
*/
