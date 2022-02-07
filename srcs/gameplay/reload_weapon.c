/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 13:49:28 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Refills the clip with ammo from the reserve.
*/

static	void	refill_clip(t_doom *data, int w_id)
{
	int old_clip_ammo;

	old_clip_ammo = data->player.wdata[w_id].clip_cur;
	data->player.wdata[w_id].clip_cur +=
	ft_min(data->player.wdata[w_id].clip_max - old_clip_ammo,
	data->player.wdata[w_id].ammo_cur);
	data->player.wdata[w_id].ammo_cur -=
	data->player.wdata[w_id].clip_cur - old_clip_ammo;
	data->player.gbl_delay = 0;
	data->player.reloading = 0;
	data->key[KEY_R] = 0;
}

/*
** Reloads the weapon after a certain amount of time has passed.
*/

void			reload_weapon(t_doom *data)
{
	int w_id;

	w_id = data->player.weapon;
	if (data->player.wdata[w_id].clip_cur != data->player.wdata[w_id].clip_max
		&& data->player.wdata[w_id].ammo_cur)
	{
		if (data->player.reloading)
		{
			if (data->player.gbl_delay <= 0)
				data->player.gbl_delay = data->player.wdata[w_id].clip_rld;
			else
			{
				data->player.gbl_delay -= SDL_GetTicks() - data->global_time;
				if (data->player.gbl_delay <= 0)
					refill_clip(data, w_id);
			}
		}
		else if (data->player.gbl_delay <= 0)
			data->player.reloading = data->key[KEY_R] ? 1
				: data->player.reloading;
	}
	else
		data->player.reloading = 0;
}
