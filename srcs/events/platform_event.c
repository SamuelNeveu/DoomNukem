/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 18:47:57 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:11:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** Allows to go back to the main menu.
*/

void		platform_event(t_doom *data)
{
	if (data->key[KEY_TAB])
	{
		data->player.platform = MENU;
		data->key[KEY_TAB] = 0;
	}
}
