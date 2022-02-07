/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:49:23 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:59:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Removes dead objects from the list.
*/

void			remove_objects(t_doom *data, t_object *l)
{
	t_object	*tmp;
	t_object	*head;

	head = l;
	while (l && l->dead == 1)
	{
		data->pfdata.list[l->i].bobstacle = 0;
		tmp = l->next;
		ft_memdel((void **)&l);
		l = tmp;
		head = l;
	}
	while (l)
	{
		tmp = l;
		l = l->next;
		while (l && l->dead == 1)
		{
			data->pfdata.list[l->i].bobstacle = 0;
			tmp->next = l->next;
			ft_memdel((void **)&l);
			l = tmp->next;
		}
	}
	l = head;
}

/*
** Makes sure what we wish to display is displayed,
** by creating a texture from a surface
*/

static void		textures(t_doom *data)
{
	SDL_LockSurface(data->screen);
	data->window = SDL_CreateTextureFromSurface(data->renderer, data->screen);
	SDL_RenderCopy(data->renderer, data->window, NULL, NULL);
	SDL_UnlockSurface(data->screen);
}

/*
** calculates FPS (shown when the minimap is shown,
** see the "minimap" folder for more info).
*/

void			get_fps(t_doom *d)
{
	d->oldtime = d->time;
	d->time = SDL_GetTicks();
	d->frametime = (d->time - d->oldtime) / 1000.0;
	d->fps = 1.0 / d->frametime;
	d->mv_speed = d->frametime * 5.0;
	d->rot_speed = d->frametime * 3.0;
}

void			display(t_doom *data)
{
	raycast_threader(data);
	monsters(data);
	objects(data, data->monster);
	objects(data, data->object);
	objects(data, data->end_flag);
	objects(data, data->items);
	remove_objects(data, data->object);
	weapons(data);
	draw_stat(data, 21, 10, W_HEIGHT - 50);
	draw_stat(data, 22, W_WIDTH - 140, W_HEIGHT - 200);
	textures(data);
	cursor(data);
	health(data);
	ammo(data);
	if (data->key[KEY_M])
		minimap(data);
	SDL_RenderPresent(data->renderer);
	SDL_SetRenderDrawColor(data->renderer, 0, 0, 0, 0);
	SDL_RenderClear(data->renderer);
	SDL_DestroyTexture(data->window);
	get_fps(data);
}
