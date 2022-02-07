/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:49:51 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

/*
** Initializes the Main Menu screen.
** doom_m = doom_menu
** doom_p = doom_pause
** doom_s = doom_settings
*/

void	init_menu(t_doom *data)
{
	data->menu.font = TTF_OpenFont("includes/assets/AmazDooMLeft.ttf", 40);
	if (!(data->menu.text = TTF_RenderText_Solid(data->menu.font,
		"ESC to RAGEQUIT", data->menu.textcolor)))
		clean_exit(data, (char*)IMG_GetError(), 0);
	data->menu.button = IMG_Load("includes/assets/tiles/buttonMenu.png");
	if (!data->menu.button)
		clean_exit(data, (char*)IMG_GetError(), 0);
	if (!(data->menu.menu1 = SDL_LoadBMP("includes/assets/menus/doom_m.bmp")))
		clean_exit(data, "SDL_LoadBMP fail1", 0);
	if (!(data->menu.menu2 = SDL_LoadBMP("includes/assets/menus/doom_p.bmp")))
		clean_exit(data, "SDL_LoadBMP fail2", 0);
	if (!(data->menu.menu3 = SDL_LoadBMP("includes/assets/menus/doom_s.bmp")))
		clean_exit(data, "SDL_LoadBMP fail3", 0);
}
