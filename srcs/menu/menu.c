/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 21:40:31 by brpinto           #+#    #+#             */
/*   Updated: 2020/07/31 19:15:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Creates a button with quote written on it.
*/

void	makebutton(t_doom *data, char *quote, SDL_Rect buttonpos)
{
	SDL_Surface	*text;
	SDL_Rect	text_pos;
	SDL_Color	color;

	if (SDL_BlitSurface(data->menu.button,
		NULL, data->screen, &buttonpos) == -1)
		clean_exit(data, "error blit surface", 0);
	color = (SDL_Color){255, 255, 255, 255};
	if (!(text = TTF_RenderText_Solid(data->menu.font, quote, color)))
		clean_exit(data, (char*)TTF_GetError(), 0);
	text_pos.x = buttonpos.x + data->menu.button->w * 0.4;
	text_pos.y = buttonpos.y + data->menu.button->h * 0.4;
	SDL_BlitSurface(text, NULL, data->screen, &text_pos);
	SDL_FreeSurface(text);
}

/*
** Allows the writing of quote in the textcolor on the screen.
*/

void	writeonscreen(t_doom *data, char *quote, SDL_Color text_color)
{
	SDL_Surface	*text;

	if (!(text = TTF_RenderText_Solid(data->menu.font, quote, text_color)))
		clean_exit(data, (char*)TTF_GetError(), 0);
	SDL_BlitSurface(text, NULL, data->screen, &data->menu.textpos);
	SDL_FreeSurface(text);
}

/*
** Shows the main menu.
*/

void	main_menu(t_doom *data)
{
	data->menu.textcolor = (SDL_Color){0, 0, 0, 0};
	SDL_FillRect(data->screen, NULL, 0x00000000);
	if (SDL_BlitSurface(data->menu.menu1, NULL, data->screen, NULL) == -1)
		clean_exit(data, "error blitsurface", 0);
	data->menu.textpos.x = (data->screen->w / 2) - (data->menu.text->w / 2);
	data->menu.textpos.y = (data->screen->h - data->menu.text->h);
	writeonscreen(data, "ESC TO RAGEQUIT", data->menu.textcolor);
	data->menu.button1pos.x = (data->screen->w / 2)
		- (data->menu.button->w) - BUTTON_MARGE;
	data->menu.button1pos.y = (data->screen->h - data->menu.button->h) * 0.99;
	data->menu.button2pos.y = (data->screen->h - data->menu.button->h) * 0.99;
	makebutton(data, "PLAY", data->menu.button1pos);
	data->menu.button2pos.x = (data->screen->w / 2) + BUTTON_MARGE;
	makebutton(data, "FORGE", data->menu.button2pos);
}

/*
** Show the pause menu.
*/

void	pause_menu(t_doom *data)
{
	SDL_FillRect(data->screen, NULL, 0x00000000);
	if (SDL_BlitSurface(data->menu.menu2, NULL, data->screen, NULL) == -1)
		ft_putstr("error blitsurface");
	data->menu.button1pos.x = (data->screen->w / 2 - data->menu.button->w) / 2;
	data->menu.button2pos.x = (data->screen->w / 2 - data->menu.button->w) / 2;
	data->menu.button1pos.y = (data->screen->h - BUTTON_MARGE)
		/ 2 - data->menu.button->h;
	makebutton(data, "RESUME", data->menu.button1pos);
}
