/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:57:36 by brpinto           #+#    #+#             */
/*   Updated: 2020/08/01 19:28:29 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	void	handle_trigger(t_doom *e, int on)
{
	if (on == 0)
		e->ed.draw = (e->ed.draw == 0) ? 1 : 0;
	else
		e->ed.draw = 0;
	if (on == 1)
		e->ed.player = (e->ed.player == 0) ? 1 : 0;
	else
		e->ed.player = 0;
	if (on == 2)
		e->ed.spawner = (e->ed.spawner == 0) ? 1 : 0;
	else
		e->ed.spawner = 0;
	if (on == 3)
		e->ed.win = (e->ed.win == 0) ? 1 : 0;
	else
		e->ed.win = 0;
	if (on == 4)
		e->ed.erase = (e->ed.erase == 0) ? 1 : 0;
	else
		e->ed.erase = 0;
	if (on == 5)
		e->ed.deco = (e->ed.deco == 0) ? 1 : 0;
	else
		e->ed.deco = 0;
}

static	void	collision_loop(t_doom *e, int fd, t_string buttons[7])
{
	int		i;
	t_point pos;
	t_point size;

	i = -1;
	while (++i < 7)
	{
		size.x = buttons[i].tex_w;
		size.y = buttons[i].tex_h;
		pos.x = buttons[i].rect.x;
		pos.y = buttons[i].rect.y;
		if (button_collide(e, pos, size))
		{
			if (i >= 0 && i <= 4)
				handle_trigger(e, i);
			else if (i == 5 && (!ft_strcmp(buttons[i].name, "Reset")))
				reset(e);
			else if (i == 6 && (!ft_strcmp(buttons[i].name, "Save")))
				e->ed.file = (create_file(e, fd) == 1) ? 1 : 0;
		}
	}
}

static	void	check_string_collision(t_doom *e, int fd)
{
	t_string	buttons[7];

	buttons[0] = e->ed.edhud.v_butt[2];
	buttons[1] = e->ed.edhud.v_butt[1];
	buttons[2] = e->ed.edhud.v_butt[3];
	buttons[3] = e->ed.edhud.v_butt[4];
	buttons[4] = e->ed.edhud.h_butt[1];
	buttons[5] = e->ed.edhud.h_butt[0];
	buttons[6] = e->ed.edhud.h_butt[2];
	collision_loop(e, fd, buttons);
}

static	void	check_arrow_collision(t_doom *e, t_carousel *car, int side)
{
	t_point	pos;
	t_point	size;
	t_arrow	arrow;

	arrow = (side == 1) ? car->larrow : car->rarrow;
	size.x = arrow.tex_w;
	size.y = arrow.tex_h;
	pos.x = arrow.rect.x;
	pos.y = arrow.rect.y;
	if (button_collide(e, pos, size))
	{
		if (side == 1)
			car->cur = (car->cur == 0)
				? car->tex_num - 1 : car->cur - 1;
		else if (side == 2)
			car->cur = (car->cur == car->tex_num - 1)
				? 0 : car->cur + 1;
		e->ed.sqr = (!ft_strcmp(car->title, "dco")) ? car->tab[car->cur].id : 0;
	}
	if ((!ft_strcmp(car->title, "wall_tex")) && car->cur == 0)
		e->ed.wall = WALL1;
	else if ((!ft_strcmp(car->title, "wall_tex")) && car->cur == 2)
		e->ed.wall = WALL2;
	else
		e->ed.wall = WALL;
}

void			check_collision(t_doom *e, int fd)
{
	t_point	pos;
	t_point	size;

	SDL_GetMouseState(&e->mouse.x, &e->mouse.y);
	if (e->key[LCLICK])
	{
		check_string_collision(e, fd);
		size.x = e->ed.edhud.deco.tab[0].tex_w * 2;
		size.y = e->ed.edhud.deco.tab[0].tex_h * 2;
		pos.x = e->ed.edhud.deco.tab[0].rect.x;
		pos.y = e->ed.edhud.deco.tab[0].rect.y;
		if (button_collide(e, pos, size))
			handle_trigger(e, 5);
		check_arrow_collision(e, &e->ed.edhud.deco, 1);
		check_arrow_collision(e, &e->ed.edhud.deco, 2);
		check_arrow_collision(e, &e->ed.edhud.wall_tex, 1);
		check_arrow_collision(e, &e->ed.edhud.wall_tex, 2);
		e->key[LCLICK] = 0;
	}
}
