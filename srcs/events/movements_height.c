/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:14:37 by apons             #+#    #+#             */
/*   Updated: 2020/07/31 20:15:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Changes the player's height by jumping or crouching.
*/

void			player_height(t_doom *data)
{
	if (data->key[KEY_SPACE])
		data->player.posz = 200;
	if (data->key[KEY_LCTRL])
		data->player.posz = -200;
	if (!data->key[KEY_SPACE] && !data->key[KEY_LCTRL])
	{
		if (data->player.posz > 0)
			data->player.posz -= 100 * data->mv_speed * 2;
		if (data->player.posz < 0)
			data->player.posz += 100 * data->mv_speed * 2;
	}
}
