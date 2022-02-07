/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:08:34 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 19:49:31 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "doom.h"

typedef	struct		s_point
{
	int				i;
	int				x;
	int				y;
}					t_point;

typedef	struct		s_obj
{
	char			*name;
	SDL_Texture		*img;
	SDL_Rect		rect;
	int				tex_h;
	int				tex_w;
	int				id;
}					t_obj;

typedef	struct		s_deco
{
	t_obj			obj;
}					t_deco;

typedef	struct		s_arrow
{
	SDL_Texture		*text;
	int				tex_w;
	int				tex_h;
	SDL_Rect		rect;
}					t_arrow;

typedef	struct		s_string
{
	char			*name;
	SDL_Rect		rect;
	SDL_Texture		*text;
	int				tex_w;
	int				tex_h;
}					t_string;

typedef	struct		s_carousel
{
	char			*title;
	t_obj			*tab;
	t_arrow			larrow;
	t_arrow			rarrow;
	int				tex_num;
	int				cur;
}					t_carousel;

typedef	struct		s_float
{
	float			x;
	float			y;
}					t_float;

typedef	struct		s_draw_ed
{
	t_float			curr;
	t_float			d;
	t_float			d_s;
	float			d_err;
	float			d_e2;
}					t_draw_ed;

typedef	struct		s_edhud
{
	t_carousel		wall_tex;
	t_carousel		deco;
	t_string		v_butt[7];
	t_string		h_butt[3];
}					t_edhud;

typedef	struct		s_editor
{
	t_point			pos;
	int				map_w;
	int				map_h;
	int				map[20][20];
	int				draw;
	int				erase;
	int				sqr;
	int				wall;
	int				player;
	int				player_exist;
	int				file;
	int				spawner;
	int				win;
	int				win_e;
	int				deco;
	int				editor_on;
	SDL_Surface		*text;
	SDL_Texture		*hud;
	char			*fname;
	t_obj			*objs;
	t_edhud			edhud;
}					t_editor;

#endif
