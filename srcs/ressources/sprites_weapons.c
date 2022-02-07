/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_weapons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 11:25:35 by apons             #+#    #+#             */
/*   Updated: 2020/07/31 21:02:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** The following functions initialize the sprites of each weapon in the game :
** fists(melee), pistol, smg, shotgun and BFG.
*/

void	sprites_melee(t_doom *data)
{
	data->wp_sprite[0].img = SDL_LoadBMP("img/weapons/melee_idle.bmp");
	data->wp_sprite[1].img = SDL_LoadBMP("img/weapons/melee_punch1a.bmp");
	data->wp_sprite[2].img = SDL_LoadBMP("img/weapons/melee_punch2a.bmp");
	data->wp_sprite[3].img = SDL_LoadBMP("img/weapons/melee_punch1b.bmp");
	data->wp_sprite[4].img = SDL_LoadBMP("img/weapons/melee_punch2b.bmp");
}

void	sprites_pistol(t_doom *data)
{
	data->wp_sprite[5].img = SDL_LoadBMP("img/weapons/pistol_idle.bmp");
	data->wp_sprite[6].img = SDL_LoadBMP("img/weapons/pistol_firing1.bmp");
	data->wp_sprite[7].img = SDL_LoadBMP("img/weapons/pistol_firing2.bmp");
	data->wp_sprite[8].img = SDL_LoadBMP("img/weapons/pistol_firing3.bmp");
	data->wp_sprite[9].img = SDL_LoadBMP("img/weapons/pistol_firing4.bmp");
}

void	sprites_smg(t_doom *data)
{
	data->wp_sprite[10].img = SDL_LoadBMP("img/weapons/smg_idle.bmp");
	data->wp_sprite[11].img = SDL_LoadBMP("img/weapons/smg_firing1.bmp");
	data->wp_sprite[12].img = SDL_LoadBMP("img/weapons/smg_firing2.bmp");
}

void	sprites_shotgun(t_doom *data)
{
	data->wp_sprite[13].img = SDL_LoadBMP("img/weapons/shotgun_idle.bmp");
	data->wp_sprite[14].img = SDL_LoadBMP("img/weapons/shotgun_firing1.bmp");
	data->wp_sprite[15].img = SDL_LoadBMP("img/weapons/shotgun_firing2.bmp");
	data->wp_sprite[16].img = SDL_LoadBMP("img/weapons/shotgun_firing3.bmp");
	data->wp_sprite[17].img = SDL_LoadBMP("img/weapons/shotgun_firing4.bmp");
}

void	sprites_bfg(t_doom *data)
{
	data->wp_sprite[18].img = SDL_LoadBMP("img/weapons/bfg_idle.bmp");
	data->wp_sprite[19].img = SDL_LoadBMP("img/weapons/bfg_charging1.bmp");
	data->wp_sprite[20].img = SDL_LoadBMP("img/weapons/bfg_charging2.bmp");
	data->wp_sprite[21].img = SDL_LoadBMP("img/weapons/bfg_charging3.bmp");
	data->wp_sprite[22].img = SDL_LoadBMP("img/weapons/bfg_charging4.bmp");
	data->wp_sprite[23].img = SDL_LoadBMP("img/weapons/bfg_charging5.bmp");
	data->wp_sprite[24].img = SDL_LoadBMP("img/weapons/bfg_charging6.bmp");
	data->wp_sprite[25].img = SDL_LoadBMP("img/weapons/bfg_charging7.bmp");
	data->wp_sprite[26].img = SDL_LoadBMP("img/weapons/bfg_charging8.bmp");
	data->wp_sprite[27].img = SDL_LoadBMP("img/weapons/bfg_charging9.bmp");
	data->wp_sprite[28].img = SDL_LoadBMP("img/weapons/bfg_charging10.bmp");
	data->wp_sprite[29].img = SDL_LoadBMP("img/weapons/bfg_firing1.bmp");
	data->wp_sprite[30].img = SDL_LoadBMP("img/weapons/bfg_firing2.bmp");
	data->wp_sprite[31].img = SDL_LoadBMP("img/weapons/bfg_firing3.bmp");
	data->wp_sprite[32].img = SDL_LoadBMP("img/weapons/bfg_firing4.bmp");
}
