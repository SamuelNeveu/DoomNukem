/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 21:03:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void			sprites_monsters(t_doom *data)
{
	if (!(data->sprite[7].img = SDL_LoadBMP("img/monsters/monster1.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[8].img = SDL_LoadBMP("img/monsters/monster2.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[9].img = SDL_LoadBMP("img/monsters/monster3.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[10].img = SDL_LoadBMP("img/monsters/monster1atk.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[11].img = SDL_LoadBMP("img/monsters/monster2atk.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[12].img = SDL_LoadBMP("img/monsters/monster3atk.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[13].img = SDL_LoadBMP("img/monsters/monster1hit.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[14].img = SDL_LoadBMP("img/monsters/monster2hit.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[15].img = SDL_LoadBMP("img/monsters/monster3hit.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
}

static void		sprites_object(t_doom *data)
{
	if (!(data->sprite[3].img = SDL_LoadBMP("img/plante.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[4].img = SDL_LoadBMP("img/cage.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[5].img = SDL_LoadBMP("img/table.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[6].img = SDL_LoadBMP("img/circle.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[20].img = SDL_LoadBMP("img/rickportal.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
}

void			sprites_weapons_hud(t_doom *data)
{
	if (!(data->sprite[21].img = SDL_LoadBMP("img/stat_bar.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	if (!(data->sprite[22].img = SDL_LoadBMP("img/stat_ammo.bmp")))
		clean_exit(data, "doom-nukem: load_sprites error", 0);
	sprites_melee(data);
	sprites_pistol(data);
	sprites_smg(data);
	sprites_shotgun(data);
	sprites_bfg(data);
	check_sprites_weapons(data);
}

void			sprites(t_doom *data)
{
	sprites_textures(data);
	sprites_monsters(data);
	sprites_object(data);
	sprites_weapons_hud(data);
	sprites_items(data);
}
