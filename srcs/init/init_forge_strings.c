/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forge_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:11:21 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** The next 2 functions create textures from text that will be on screen,
** the first one for the words under the grid,
** the other one for the right side of the grid.
*/

static	void	create_hstring(t_doom *e)
{
	int		i;
	int		tex_w;
	t_point	pos;

	i = -1;
	tex_w = 0;
	pos.y = W_HEIGHT - 40;
	while (++i < 3)
	{
		if (i > 0)
		{
			tex_w += e->ed.edhud.h_butt[i - 1].tex_w;
			pos.x = 80 + (80 * i) + tex_w;
		}
		else if (i == 0)
			pos.x = 80;
		e->ed.edhud.h_butt[i] = create_texture(e, pos, e->ed.edhud.h_butt[i]);
	}
}

static void		create_vstring(t_doom *e)
{
	int		i;
	int		tex_h;
	t_point	pos;

	i = -1;
	tex_h = 0;
	pos.x = 0;
	while (++i < 7)
	{
		pos.y = (i == 0) ? 20 : 0;
		if (i >= 1 && i <= 6)
		{
			tex_h += e->ed.edhud.v_butt[i - 1].tex_h;
			pos.y = (i == 6) ? 20 * (i + 7) +
			(e->ed.edhud.wall_tex.tab[0].tex_h * 2) + tex_h : 20 * (i + 5)
				+ tex_h;
		}
		e->ed.edhud.v_butt[i] = create_texture(e, pos, e->ed.edhud.v_butt[i]);
		e->ed.edhud.v_butt[i].rect.x = W_WIDTH / 2 + (W_WIDTH / 4)
			- (e->ed.edhud.v_butt[i].tex_w / 2);
	}
}

/*
** Initalizes char string that are then going to be converted into textures.
*/

void			init_string(t_doom *e)
{
	e->ed.edhud.v_butt[0].name = "DooM Map Editor";
	e->ed.edhud.v_butt[1].name = "Player";
	e->ed.edhud.v_butt[2].name = "Walls";
	e->ed.edhud.v_butt[3].name = "Spawners";
	e->ed.edhud.v_butt[4].name = "Victory";
	e->ed.edhud.v_butt[5].name = "Walls textures";
	e->ed.edhud.v_butt[6].name = "Useless objetcs";
	create_vstring(e);
	e->ed.edhud.h_butt[0].name = "Reset";
	e->ed.edhud.h_butt[1].name = "Erase";
	e->ed.edhud.h_butt[2].name = "Save";
	create_hstring(e);
}
