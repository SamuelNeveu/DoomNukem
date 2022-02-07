/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:04:34 by brpinto           #+#    #+#             */
/*   Updated: 2020/08/01 19:31:52 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	void	render_carousel(t_doom *e)
{
	t_obj	deco;
	t_obj	wall;

	deco = e->ed.edhud.deco.tab[e->ed.edhud.deco.cur];
	SDL_RenderCopy(e->renderer, deco.img, NULL, &deco.rect);
	SDL_RenderCopy(e->renderer, e->ed.edhud.deco.larrow.text
		, NULL, &e->ed.edhud.deco.larrow.rect);
	SDL_RenderCopy(e->renderer, e->ed.edhud.deco.rarrow.text
		, NULL, &e->ed.edhud.deco.rarrow.rect);
	wall = e->ed.edhud.wall_tex.tab[e->ed.edhud.wall_tex.cur];
	SDL_RenderCopy(e->renderer, wall.img, NULL, &wall.rect);
	SDL_RenderCopy(e->renderer, e->ed.edhud.wall_tex.larrow.text
		, NULL, &e->ed.edhud.wall_tex.larrow.rect);
	SDL_RenderCopy(e->renderer, e->ed.edhud.deco.rarrow.text
		, NULL, &e->ed.edhud.wall_tex.rarrow.rect);
}

static	void	render_elements(t_doom *e)
{
	int	i;

	i = 0;
	render_carousel(e);
	while (i < 7)
	{
		if (i >= 0 && i <= 3)
			SDL_RenderCopy(e->renderer, e->ed.edhud.h_butt[i].text, NULL
					, &e->ed.edhud.h_butt[i].rect);
		SDL_RenderCopy(e->renderer, e->ed.edhud.v_butt[i].text, NULL
				, &e->ed.edhud.v_butt[i].rect);
		i++;
	}
}

void			editor(t_doom *e)
{
	int fd;

	fd = 0;
	if (e->ed.draw)
		set_wall(e);
	if (e->ed.erase)
		set_floor(e);
	if (e->ed.win)
		set_win(e);
	if (e->ed.deco)
		set_objects(e);
	if (e->ed.player)
		set_player(e);
	if (e->ed.spawner)
		set_spawner(e);
	refresh_map(e);
	draw_grid(e);
	render_elements(e);
	check_collision(e, fd);
}
