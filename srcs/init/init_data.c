/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:26:23 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/30 14:55:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Initializes the program's game functions so they can be used quickly.
*/

static	void	init_usr_fc(t_doom *data)
{
	data->player.platform = MENU;
	data->player.f[0] = menu_start;
	data->player.f[1] = gameplay;
	data->player.f[2] = menu_pause;
	data->player.f[3] = forge;
	data->player.f[4] = game_end;
}

/*
** Initializes the player's starting position on the map.
*/

static	void	init_usr_pos(t_doom *data)
{
	data->player.y = data->map.posx + 0.5;
	data->player.x = data->map.posy + 0.5;
	data->player.dirx = 1;
	data->player.diry = 0;
	data->player.posz = 0;
}

/*
** Initializes the player's data in the player structure
** as well as few other variables.
*/

void			init_data(t_doom *data)
{
	init_usr_fc(data);
	data->map.len = data->map.height * data->map.width;
	data->map.depth = data->map.width > data->map.height
		? data->map.width : data->map.height;
	init_usr_pos(data);
	data->player.fov = 3.14159f / 4;
	data->player.health = 200;
	data->player.health_max = 200;
	data->player.weapon = 0;
	data->map.sc_x = 4;
	data->player.planex = 0;
	data->player.planey = data->player.fov;
	data->player.pitch = 0;
	data->player.fist_side = 0;
	data->player.gbl_delay = 0;
	data->player.reloading = 0;
	data->key[MOUSE] = 1;
	data->obj_intens = 0.7;
	data->time = 1;
	data->floorstyle = 1;
	data->fog = 3;
}
