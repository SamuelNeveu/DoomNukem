/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datagame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:41:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Loads the object's stats into list.
*/

void			help_get_list_items(t_doom *data, t_object *list, int i, int j)
{
	list->next = NULL;
	list->x = i + 0.5;
	list->y = j + 0.5;
	list->type = data->map.map[i][j];
	list->hp = get_objhp(data, list);
	list->hp_max = list->hp;
	list->speed = 0.2f;
	list->si = list->type % SITEMS - 1;
	list->i = list->x + data->map.width * list->y;
	list->sprite = data->sp_items[list->si];
	data->map.map[i][j] = 0;
}

void			help_get_list(t_doom *data, t_object *list, int i, int j)
{
	list->next = NULL;
	list->x = i + 0.5;
	list->y = j + 0.5;
	list->type = data->map.map[i][j];
	list->hp = get_objhp(data, list);
	list->hp_max = list->hp;
	list->speed = 0.2f;
	list->si = list->type;
	list->i = list->x + data->map.width * list->y;
	list->sprite = data->sprite[list->si];
}

/*
** Gets the list of all objects and puts them into list,
** with min and max being the id range.
*/

t_object		*get_list(t_doom *data, int min, int max)
{
	t_object	*head;
	t_object	*tmp;
	int			i;
	int			j;

	head = NULL;
	tmp = head;
	i = -1;
	while (++i < data->map.width)
	{
		j = -1;
		while (++j < data->map.height)
		{
			if (data->map.map[i][j] >= min && data->map.map[i][j] <= max)
			{
				if (tmp == NULL)
					if (!(tmp = (t_object *)ft_memalloc(sizeof(t_object))))
						return (NULL);
				get_list_bis(data, i, j, tmp);
				head = lst_pushback(head, tmp);
				tmp = tmp->next;
			}
		}
	}
	return (head);
}

/*
** Loads weapons data.
*/

void			get_weapon_data(t_doom *data)
{
	get_fists_data(data);
	get_pistol_data(data);
	get_smg_data(data);
	get_shotgun_data(data);
	get_bfg_data(data);
}

/*
** Loads everything allowing the program to run : sprites, objects, weapons.
*/

void			load_datagame(t_doom *data)
{
	SDL_GetWindowPosition(data->pwindow, &data->wx, &data->wy);
	sprites(data);
	data->object = get_list(data, 3, 5);
	data->monster = get_list(data, 6, 6);
	data->end_flag = get_list(data, 14, 14);
	data->items = get_list(data, 15, 20);
	get_nodes(data);
	get_weapon_data(data);
}
