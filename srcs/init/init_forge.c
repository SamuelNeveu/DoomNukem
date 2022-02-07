/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:08:32 by brpinto           #+#    #+#             */
/*   Updated: 2020/08/01 19:47:53 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

/*
** Initialize a texture or an object so it can be placed in the list
** that the carousel will use.
*/

static	t_obj		obj_init(t_doom *e, char *path, int y)
{
	t_obj		obj;
	SDL_Surface	*surf;
	char		*str;
	int			path_id;

	str = ft_strsub(path, 11, 5);
	path_id = atoi(str);
	free(str);
	surf = IMG_Load(path);
	obj.img = SDL_CreateTextureFromSurface(e->renderer, surf);
	obj.tex_w = 0;
	obj.tex_h = 0;
	SDL_QueryTexture(obj.img, NULL, NULL, &obj.tex_w, &obj.tex_h);
	obj.id = path_id;
	obj.rect.h = surf->h * 2;
	obj.rect.w = surf->w * 2;
	obj.rect.x = (W_WIDTH / 2) + (W_WIDTH / 4) - surf->w;
	obj.rect.y = y;
	SDL_FreeSurface(surf);
	return (obj);
}

/*
** Initializes the arrows textures that will allow the "spinning"
** of the carousel.
*/

static	t_arrow		init_arrow(t_doom *d, char *path, t_obj obj, t_point start)
{
	t_arrow		arrow;
	SDL_Surface *surf;

	surf = IMG_Load(path);
	arrow.text = SDL_CreateTextureFromSurface(d->renderer, surf);
	arrow.tex_w = 0;
	arrow.tex_h = 0;
	SDL_QueryTexture(arrow.text, NULL, NULL, &arrow.tex_w, &arrow.tex_h);
	arrow.rect.y = start.y + obj.tex_h - arrow.tex_h / 2;
	arrow.rect.x = start.x;
	arrow.rect.h = surf->h;
	arrow.rect.w = surf->w;
	SDL_FreeSurface(surf);
	return (arrow);
}

/*
** Initializes the carousels for both the walls and the objects to be placed.
*/

static	t_carousel	init_carousel(t_doom *e, char tab[3][21], int y, int len)
{
	int			i;
	t_carousel	car;
	t_point		start;

	if (!(car.tab = malloc(sizeof(t_obj) * len)))
		clean_exit(e, "Obj tab malloc failed\n", 0);
	i = -1;
	while (++i < len)
		car.tab[i] = obj_init(e, tab[i], y);
	car.tex_num = i;
	start.x = car.tab[i - 1].rect.x - (car.tab[i - 1].tex_w / 2) - 20;
	start.y = y;
	car.larrow = init_arrow(e, "img/editor/arleft.png", car.tab[i - 1], start);
	start.x = car.tab[i - 1].rect.x + (car.tab[i - 1].tex_w * 2) + 20;
	start.y = y;
	car.rarrow = init_arrow(e, "img/editor/arright.png", car.tab[i - 1], start);
	car.cur = 0;
	return (car);
}

/*
** Initializes carousel images path to avoid malloc.
*/

static	void		ft_fillstr(char *str, char (*tofill)[21])
{
	int i;

	i = -1;
	while (++i < 21)
		(*tofill)[i] = str[i];
}

/*
** Initializes the forge (map editor).
*/

void				init_forge(t_doom *data)
{
	char	deco_tab[5][21];
	char	wall_tab[3][21];

	ft_fillstr("img/editor/03pla.png\0", &(deco_tab[0]));
	ft_fillstr("img/editor/04tab.png\0", &(deco_tab[1]));
	ft_fillstr("img/editor/05cag.png\0", &(deco_tab[2]));
	ft_fillstr("img/editor/15amm.png\0", &(deco_tab[3]));
	ft_fillstr("img/editor/16hea.png\0", &(deco_tab[4]));
	ft_fillstr("img/editor/10uni.png\0", &(wall_tab[0]));
	ft_fillstr("img/editor/01wal.png\0", &(wall_tab[1]));
	ft_fillstr("img/editor/11eye.png\0", &(wall_tab[2]));
	data->ed.edhud.deco = init_carousel(data, deco_tab
		, (W_HEIGHT - (W_HEIGHT / 4)), 5);
	data->ed.edhud.deco.title = "dco";
	data->ed.edhud.wall_tex = init_carousel(data, wall_tab
		, ((W_HEIGHT / 2) - 10), 3);
	data->ed.edhud.wall_tex.title = "wall_tex";
	init_string(data);
	data->ed.deco = FLOOR;
	data->ed.wall = WALL;
	data->ed.sqr = PLANT;
	data->ed.map_w = 20;
	data->ed.map_h = 20;
	data->ed.editor_on = 1;
}
