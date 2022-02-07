/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weapon_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:19:58 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** The following functions load the weapon's variables into wdata.
*/

void	get_fists_data(t_doom *data)
{
	data->player.wdata[0].damage = 60;
	data->player.wdata[0].delay = 330;
	data->player.wdata[0].range = 2;
	data->player.wdata[0].clip_cur = 1000000;
	data->player.wdata[0].clip_max = 1000000;
	data->player.wdata[0].clip_rld = 1;
	data->player.wdata[0].ammo_cur = 15000000;
	data->player.wdata[0].ammo_max = 15000000;
	data->player.wdata[0].si = 0;
	data->player.wdata[0].name = "fists";
}

void	get_pistol_data(t_doom *data)
{
	data->player.wdata[1].damage = 75;
	data->player.wdata[1].delay = 150;
	data->player.wdata[1].range = data->map.depth;
	data->player.wdata[1].clip_cur = 12;
	data->player.wdata[1].clip_max = 12;
	data->player.wdata[1].clip_rld = 1600;
	data->player.wdata[1].ammo_cur = 60;
	data->player.wdata[1].ammo_max = 60;
	data->player.wdata[1].si = 5;
	data->player.wdata[1].name = "pistol";
}

void	get_smg_data(t_doom *data)
{
	data->player.wdata[2].damage = 40;
	data->player.wdata[2].delay = 100;
	data->player.wdata[2].range = data->map.depth;
	data->player.wdata[2].clip_cur = 30;
	data->player.wdata[2].clip_max = 30;
	data->player.wdata[2].clip_rld = 2100;
	data->player.wdata[2].ammo_cur = 150;
	data->player.wdata[2].ammo_max = 150;
	data->player.wdata[2].si = 10;
	data->player.wdata[2].name = "smg";
}

void	get_shotgun_data(t_doom *data)
{
	data->player.wdata[3].damage = 200;
	data->player.wdata[3].delay = 1200;
	data->player.wdata[3].range = data->map.depth;
	data->player.wdata[3].clip_cur = 4;
	data->player.wdata[3].clip_max = 4;
	data->player.wdata[3].clip_rld = 2500;
	data->player.wdata[3].ammo_cur = 24;
	data->player.wdata[3].ammo_max = 24;
	data->player.wdata[3].si = 13;
	data->player.wdata[3].name = "shotgun";
}

void	get_bfg_data(t_doom *data)
{
	data->player.wdata[4].damage = 600;
	data->player.wdata[4].delay = 850;
	data->player.wdata[4].range = data->map.depth;
	data->player.wdata[4].clip_cur = 1;
	data->player.wdata[4].clip_max = 1;
	data->player.wdata[4].clip_rld = 3000;
	data->player.wdata[4].ammo_cur = 3;
	data->player.wdata[4].ammo_max = 3;
	data->player.wdata[4].si = 18;
	data->player.wdata[4].name = "bfg";
}
