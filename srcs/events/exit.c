/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:24:12 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 23:47:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Exits the program, and displays an error message if need be.
*/

void			editor_free(t_doom *e)
{
	int i;

	if (e->ed.editor_on == 1)
	{
		i = 0;
		SDL_DestroyTexture(e->ed.edhud.deco.larrow.text);
		SDL_DestroyTexture(e->ed.edhud.deco.rarrow.text);
		SDL_DestroyTexture(e->ed.edhud.wall_tex.larrow.text);
		SDL_DestroyTexture(e->ed.edhud.wall_tex.rarrow.text);
		while (i < 3)
		{
			SDL_DestroyTexture(e->ed.edhud.deco.tab[i].img);
			SDL_DestroyTexture(e->ed.edhud.wall_tex.tab[i].img);
			i++;
		}
	}
}

void			map_free(t_map *map)
{
	int i;

	i = map->width - 1;
	while (--i >= 0)
		free((void*)map->map[i]);
}

void			clean_exit(t_doom *data, char *str, int token)
{
	if (data)
	{
		if (data->sdl_on)
		{
			free_surfaces(data);
			if (data->sound.token >= 1)
				free_sound(data);
			Mix_CloseAudio();
			free_ttf(data);
			if (data->pwindow)
				SDL_DestroyWindow(data->pwindow);
			SDL_Quit();
		}
		map_free(&data->map);
		lst_free(data->object);
		lst_free(data->monster);
		lst_free(data->end_flag);
		lst_free(data->items);
		ft_memdel((void **)&data->pfdata.list);
		editor_free(data);
	}
	if (str)
		ft_putendl_fd(str, 2);
	exit(token ? EXIT_SUCCESS : EXIT_FAILURE);
}
