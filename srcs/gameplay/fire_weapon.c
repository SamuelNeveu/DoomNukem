/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 17:52:15 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Turns off the BFG by resetting associated variables to 0.
*/

static void	uncharge_weapon(t_doom *data)
{
	data->player.gbl_delay = 0;
	data->player.charging = 0;
}

/*
** Makes weapon delay tick and turns LCLICK off if the weapon is semiautomatic.
*/

static void	tick_and_click(t_doom *data, int w_id)
{
	data->player.gbl_delay -= SDL_GetTicks() - data->global_time;
	if (((w_id != WP_SMG && w_id != WP_BFG)
	|| !data->player.wdata[w_id].clip_cur) && data->player.gbl_delay <= 0)
		data->key[LCLICK] = 0;
}

/*
** Function handling the weapon firing if it was successful. Shoots until
** either the delay is above 0 or not more bullets remains in the clip.
*/

static void	fire_weapon_success(t_doom *data, int w_id)
{
	if (w_id == WP_BFG && data->player.gbl_delay <= 0 && !data->player.charging)
	{
		data->player.gbl_delay = data->player.wdata[w_id].delay * 2;
		data->player.charging = 1;
	}
	else
	{
		w_id = data->player.weapon;
		while (data->player.gbl_delay <= 0 && data->player.wdata[w_id].clip_cur)
		{
			shoot(data);
			data->player.wdata[w_id].clip_cur--;
			if (w_id == WP_FISTS)
				data->player.fist_side = data->player.fist_side ? 0 : 2;
			data->player.gbl_delay += data->player.wdata[w_id].delay;
			data->player.charging = 0;
		}
	}
}

/*
** Sets variables that allow for the weapon to reload
** by left-clicking if the weapon is empty.
*/

static void	fire_weapon_failure(t_doom *data)
{
	if (data->player.wdata[data->player.weapon].ammo_cur)
		data->key[KEY_R] = 1;
	data->key[LCLICK] = 0;
}

/*
** Handles weapon charge, fire, and reload if necessary.
*/

void		fire_weapon(t_doom *data)
{
	int w_id;

	if (!data->player.reloading)
	{
		w_id = data->player.weapon;
		if (w_id == WP_BFG && !data->key[LCLICK] && data->player.charging)
			uncharge_weapon(data);
		else if (data->player.gbl_delay > 0)
			tick_and_click(data, w_id);
		else if (data->player.gbl_delay <= 0 && data->key[LCLICK])
		{
			if (data->player.wdata[w_id].clip_cur)
				fire_weapon_success(data, w_id);
			else
			{
				fire_weapon_failure(data);
			}
		}
	}
}
