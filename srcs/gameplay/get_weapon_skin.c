/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weapon_skin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 11:55:31 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Looks for the right sprite ID when using the SMG then returns it.
*/

static int	get_wp_skin_help_l(t_doom *data, int cur, int max)
{
	if (!data->player.reloading)
	{
		if (cur >= max * 0.66)
			return (11);
		if (cur >= max * 0.33)
			return (12);
	}
	return (10);
}

/*
** Looks for the right sprite ID when using the SMG or the shotgun
** then returns it.
*/

static	int	get_weapon_skin_l(t_doom *data)
{
	int cur;
	int max;

	cur = data->player.gbl_delay;
	max = data->player.wdata[data->player.weapon].delay;
	if (data->player.weapon == WP_SMG)
		return (get_wp_skin_help_l(data, cur, max));
	if (data->player.reloading)
		return (13);
	if (cur >= max * 0.85)
		return (14);
	if (cur >= max * 0.70 || (cur < max * 0.10))
		return (13);
	if (cur >= max * 0.60 || (cur >= max * 0.10 && cur < max * 0.20))
		return (15);
	if (cur >= max * 0.50 || (cur >= max * 0.20 && cur < max * 0.30))
		return (16);
	return (17);
}

/*
** Looks for the right BFG sprite ID when charging up then returns it.
*/

static int	get_wp_skin_help_xl(t_doom *data)
{
	int cur;
	int max;

	cur = data->player.gbl_delay;
	max = data->player.wdata[data->player.weapon].delay * 2;
	if (cur >= max * 0.90)
		return (19);
	if (cur >= max * 0.80)
		return (20);
	if (cur >= max * 0.70)
		return (21);
	if (cur >= max * 0.60)
		return (22);
	if (cur >= max * 0.50)
		return (23);
	if (cur >= max * 0.40)
		return (24);
	if (cur >= max * 0.30)
		return (25);
	if (cur >= max * 0.20)
		return (26);
	if (cur >= max * 0.10)
		return (27);
	return (28);
}

/*
** Looks for the right BFG sprite ID when the projectile is fired
** then returns it.
*/

static int	get_weapon_skin_xl(t_doom *data)
{
	int cur;
	int max;

	if (!data->player.reloading)
	{
		if (data->player.charging)
			return (get_wp_skin_help_xl(data));
		cur = data->player.gbl_delay;
		max = data->player.wdata[data->player.weapon].delay;
		if (cur >= max * 0.55)
			return (29);
		if (cur >= max * 0.40)
			return (30);
		if (cur >= max * 0.20)
			return (31);
		if (cur > 0)
			return (32);
	}
	return (18);
}

/*
** Looks for the right weapon sprite ID according to delay on weapon.
*/

int			get_weapon_skin(t_doom *data)
{
	if (data->player.weapon <= WP_PISTOL)
		return (get_weapon_skin_s(data));
	else if (data->player.weapon <= WP_SHOTGUN)
		return (get_weapon_skin_l(data));
	return (get_weapon_skin_xl(data));
}
