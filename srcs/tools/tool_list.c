/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:05:22 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 21:03:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void			lst_free(t_object *list)
{
	t_object	*tmp;

	while (list)
	{
		tmp = list->next;
		ft_memdel((void **)&list);
		if (tmp)
			list = tmp;
	}
}

int				lst_len(t_object *list)
{
	int			i;
	t_object	*tmp;

	if (list == NULL)
		return (0);
	tmp = list;
	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

t_object		*lst_pushback(t_object *list, t_object *node)
{
	t_object	*head;

	head = list;
	if (node == NULL)
	{
		lst_free(head);
		return (NULL);
	}
	if (list)
	{
		while (list->next != NULL)
			list = list->next;
		if (!(list->next = node))
		{
			lst_free(head);
			return (NULL);
		}
		list = head;
	}
	else
		return (node);
	return (list);
}

void			free_surfaces(t_doom *data)
{
	int	i;

	i = SNB;
	while (--i >= 0)
		if (data->sprite[i].img)
			SDL_FreeSurface(data->sprite[i].img);
	i = WPS_NB;
	while (--i >= 0)
		if (data->wp_sprite[i].img)
			SDL_FreeSurface(data->wp_sprite[i].img);
	i = SITEMS;
	while (--i >= 0)
		if (data->sp_items[i].img)
			SDL_FreeSurface(data->wp_sprite[i].img);
	if (data->screen)
		SDL_FreeSurface(data->screen);
}

void			free_ttf(t_doom *data)
{
	TTF_CloseFont(data->menu.font);
	TTF_Quit();
}

/*
**void after_main() __attribute__((destructor));
**
**void after_main()
**{
**	while (1);
**}
*/
