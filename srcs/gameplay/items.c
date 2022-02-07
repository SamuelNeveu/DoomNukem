/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:53:50 by user42            #+#    #+#             */
/*   Updated: 2020/07/31 20:30:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static void		fill_magasin(t_doom *d)
{
	int i;

	i = -1;
	while (++i < WP_NB)
	{
		d->player.wdata[i].ammo_cur = d->player.wdata[i].ammo_max;
		d->player.wdata[i].clip_cur = d->player.wdata[i].clip_max;
	}
}

void			wich_items(t_doom *d, t_object *head)
{
	if (head->type == 15)
	{
		if (d->player.health < d->player.health_max)
		{
			d->player.health = d->player.health_max;
			head->dead = 1;
			play_sound(d, d->sound.playerspawn, 2);
		}
	}
	if (head->type == 16)
	{
		fill_magasin(d);
		play_sound(d, d->sound.playerspawn, 2);
		head->dead = 1;
	}
}

void			check_item_pos(t_doom *d)
{
	t_object *head;

	head = d->items;
	while (head)
	{
		if (!head->dead && (int)d->player.x == (int)head->x
			&& (int)d->player.y == (int)head->y)
			wich_items(d, head);
		head = head->next;
	}
}
