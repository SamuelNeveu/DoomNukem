/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_ammo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:09:36 by apons             #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Convert either ammo in the clip or in the reserve into text.
*/

static	void	gat_support(t_doom *data, int ammo_clip, int w_id)
{
	if (ammo_clip == 1)
	{
		data->player.hud_text1 = ft_itoa(data->player.wdata[w_id].clip_cur);
		data->player.hud_text2 = ft_itoa(data->player.wdata[w_id].clip_max);
	}
	else
	{
		data->player.hud_text1 = ft_itoa(data->player.wdata[w_id].ammo_cur);
		data->player.hud_text2 = ft_itoa(data->player.wdata[w_id].ammo_max);
	}
}

/*
** Deletes hud_text if possible and exits the program.
*/

void			gat_exit(t_doom *data)
{
	ft_strdel(&data->player.hud_text1);
	ft_strdel(&data->player.hud_text2);
	clean_exit(data, "hud_error", 1);
}

/*
** Convert ammo in clip or in reserve into text
** that is returned by the function.
*/

static	char	*get_ammo_text(t_doom *data, int ammo_clip)
{
	int		w_id;
	char	*tmp;

	w_id = data->player.weapon;
	gat_support(data, ammo_clip, w_id);
	tmp = data->player.hud_text1;
	tmp = ft_strjoin_free(tmp, "/", 1);
	data->player.hud_text1 = ft_strjoin_free(tmp, data->player.hud_text2, 2);
	free(tmp);
	return (data->player.hud_text1);
}

/*
** Writes text on the screen.
*/

static	void	write_text(t_doom *d, char *txt, SDL_Color color, SDL_Rect rect)
{
	SDL_Surface	*surface_text;
	SDL_Texture	*result;

	if (!(surface_text = TTF_RenderText_Solid(d->font.police, txt, color)))
	{
		ft_strdel(&txt);
		clean_exit(d, "hud_error", 1);
	}
	if (!(result = SDL_CreateTextureFromSurface(d->renderer, surface_text)))
	{
		SDL_FreeSurface(surface_text);
		clean_exit(d, "hud error", 1);
	}
	SDL_FreeSurface(surface_text);
	if (SDL_RenderCopy(d->renderer, result, NULL, &rect) < 0)
	{
		SDL_DestroyTexture(result);
		clean_exit(d, "hud error", 1);
	}
}

/*
** Display the ammo text for the current weapon on the screen.
*/

void			ammo(t_doom *data)
{
	SDL_Color	color;
	SDL_Rect	rect;
	char		*text;
	int			w_id;
	char		*tmp;

	w_id = data->player.weapon;
	color = (SDL_Color){200, 200, 200, 255};
	rect = (SDL_Rect){W_WIDTH - 125, W_HEIGHT - 185, 103, 65};
	if (!(tmp = ft_strnew(ft_strlen(data->player.wdata[w_id].name))))
		clean_exit(data, "hud_error", 1);
	text = ft_strcat(tmp, data->player.wdata[w_id].name);
	write_text(data, text, color, rect);
	free(tmp);
	if (w_id != 0)
	{
		text = get_ammo_text(data, 1);
		rect = (SDL_Rect){W_WIDTH - 125, W_HEIGHT - 135, 103, 65};
		write_text(data, text, color, rect);
		free(text);
		text = get_ammo_text(data, 2);
		rect = (SDL_Rect){W_WIDTH - 125, W_HEIGHT - 80, 103, 65};
		write_text(data, text, color, rect);
		free(text);
	}
}
