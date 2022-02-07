/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Deals the current weapon damage to the monster, plays according sounds
** and declares it dead if its HP reaches 0.
*/

void			deal_damage_tomonster(t_doom *data, t_object *list, int damage)
{
	if (list == NULL || list->type < 7)
		return ;
	list->hp -= damage;
	if (list->hp < 1)
	{
		++data->kill_score;
		list->dead = 1;
		list->si = 28;
		play_sound(data, data->sound.nmideath, 3);
	}
	else
	{
		list->si = list->type + 6;
		list->sprite = data->sprite[list->si];
		play_sound(data, data->sound.nmihit, 3);
	}
}

/*
** Checks if the monster was hit by the player's current weapon.
*/

static int		hitbox(t_doom *data)
{
	int		i;
	int		range;
	int		ms;

	ms = W_WIDTH / 2;
	if (data->monster->data.dst_fromplayer
			> data->player.wdata[data->player.weapon].range)
		return (0);
	range = ms / data->monster->data.dst_fromplayer;
	i = ms - range - 1;
	if ((data->monster->data.mid < ms + range
		&& data->monster->data.mid > ms - range))
	{
		while (++i < ms + range)
			if (data->map.depth_buffer[i]
				>= data->monster->data.dst_fromplayer)
				return (1);
	}
	return (0);
}

/*
** Checks if one or more monsters have been hit and
** resolves the damage dealt accordingly.
*/

static void		shoot_impact(t_doom *data)
{
	t_object	*head;

	head = data->monster;
	while (data->monster)
	{
		if (data->monster->type > 6)
			if (hitbox(data) == 1)
				deal_damage_tomonster(data, data->monster,
					data->player.wdata[data->player.weapon].damage);
		data->monster = data->monster->next;
	}
	data->monster = head;
}

/*
** Plays the right shooting sound and check if monsters were hit.
*/

void			shoot(t_doom *data)
{
	if (data->player.weapon == 0)
		play_sound(data, data->sound.hand, 2);
	else if (data->player.weapon == 1)
		play_sound(data, data->sound.gun, 2);
	else if (data->player.weapon == 2)
		play_sound(data, data->sound.shotgun, 2);
	else
		play_sound(data, data->sound.fusil, 2);
	shoot_impact(data);
}
