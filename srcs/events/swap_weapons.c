/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:00:59 by apons             #+#    #+#             */
/*   Updated: 2020/07/31 20:17:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Swaps weapons using number keys and plays according sound.
*/

void	swap_weapons(t_doom *data)
{
	int w_id;

	w_id = data->player.weapon;
	if (data->player.gbl_delay <= 0)
	{
		if (data->key[KEY_NUM1] && w_id != 0)
			data->player.weapon = 0;
		else if (data->key[KEY_NUM2] && w_id != 1)
			data->player.weapon = 1;
		else if (data->key[KEY_NUM3] && w_id != 2)
			data->player.weapon = 2;
		else if (data->key[KEY_NUM4] && w_id != 3)
			data->player.weapon = 3;
		else if (data->key[KEY_NUM5] && w_id != 4)
			data->player.weapon = 4;
		if (w_id != data->player.weapon)
		{
			if (data->player.weapon == 0)
				play_sound(data, data->sound.hand, 6);
			else
				play_sound(data, data->sound.switchgun, 6);
		}
	}
}
