/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:05:22 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:16:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Checks if the player is in a wall and keeps the player position if the
*/

static void		in_wall(t_doom *d, float sx, float sy)
{
	float x;
	float y;

	x = d->player.x + sx;
	y = d->player.y + sy;
	if (d->map.map[(int)d->player.x][(int)y] == 0
		&& !(d->map.map[(int)d->player.x][(int)(y - 0.04)] != 0
			|| (d->map.map[(int)d->player.x][(int)(y + 0.04)] != 0)))
		d->player.y = y;
	if (d->map.map[(int)x][(int)d->player.y] == 0
		&& !(d->map.map[(int)(x - 0.04)][(int)d->player.y] != 0
			|| (d->map.map[(int)(x + 0.04)][(int)d->player.y] != 0)))
		d->player.x = x;
}

/*
** Checks if the player is in range of monsters.
*/

static int		is_outrange(t_doom *data, float sx, float sy)
{
	t_object	*head;
	int			x;
	int			y;

	x = data->player.x + sx;
	y = data->player.y + sy;
	if (y < 0 || y >= data->map.height)
		return (1);
	else if (x < 0 || x >= data->map.width)
		return (1);
	head = data->monster;
	while (data->monster)
	{
		if (distance_calc(x, y,
		data->monster->x, data->monster->y) < 0.20)
		{
			data->monster = head;
			return (1);
		}
		data->monster = data->monster->next;
	}
	data->monster = head;
	return (0);
}

/*
** Makes the player move forward or backward according to input
** movement and makes them win if they are at the end.
*/

static void		move_maker(t_doom *data, int walkdir, double shift)
{
	double dx;
	double dy;

	dx = walkdir * data->player.dirx * data->mv_speed * shift;
	dy = walkdir * data->player.diry * data->mv_speed * shift;
	if (!is_outrange(data, dx, dy))
	{
		in_wall(data, dx, dy);
		SDL_FlushEvent(SDL_KEYDOWN);
	}
	data->player.pos = (int)data->player.x
		+ data->map.width * (int)data->player.y;
	if ((int)data->player.x == data->end.x
		&& (int)data->player.y == data->end.y)
		game_win(data);
	check_item_pos(data);
}

/*
** Makes the player move left or right according to input
** movement and makes them win if they are at the end.
*/

static void		move_lateral(t_doom *d, int lat)
{
	double dx;
	double dy;

	dx = lat * d->player.diry * d->mv_speed / 2;
	dy = -lat * d->player.dirx * d->mv_speed / 2;
	if (!is_outrange(d, dx, dy))
	{
		in_wall(d, dx, dy);
		SDL_FlushEvent(SDL_KEYDOWN);
		d->player.pos = (int)d->player.x
			+ d->map.width * (int)d->player.y;
	}
	if ((int)d->player.x == d->end.x
		&& (int)d->player.y == d->end.y)
		game_win(d);
	check_item_pos(d);
}

/*
** Handles player's movement.
*/

void			movements(t_doom *data)
{
	float	shift;

	shift = data->key[KEY_SHIFT] ? 1.7f : 1;
	if (data->key[KEY_E])
		mouse(data, 5, 1);
	if (data->key[KEY_Q])
		mouse(data, 5, -1);
	if (data->key[KEY_A])
		move_lateral(data, 1);
	if (data->key[KEY_D])
		move_lateral(data, -1);
	if (data->key[KEY_W])
		move_maker(data, 1, shift);
	if (data->key[KEY_S])
		move_maker(data, -1, shift);
	player_height(data);
	mouse_events(data);
}
