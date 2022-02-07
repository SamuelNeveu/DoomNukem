/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weapon_skin_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:48:03 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Looks for the right sprite ID when using the fists or the pistol.
*/

int	get_weapon_skin_s(t_doom *data)
{
	int cur;
	int max;

	cur = data->player.gbl_delay;
	max = data->player.wdata[data->player.weapon].delay;
	if (data->player.weapon == WP_FISTS)
	{
		if (cur <= 0 || data->player.reloading)
			return (0);
		if (cur >= max * 0.95 || (cur < max * 0.15))
			return (1 + data->player.fist_side);
		return (2 + data->player.fist_side);
	}
	if (!data->player.reloading)
	{
		if (cur >= max * 0.80)
			return (6);
		if (cur >= max * 0.60)
			return (7);
		if (cur >= max * 0.40)
			return (8);
		if (cur >= max * 0.10)
			return (9);
	}
	return (5);
}
