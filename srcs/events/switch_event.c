/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:09:57 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/30 14:53:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

/*
** Swaps between the different floor settings.
*/

void			switch_floor(t_doom *d)
{
	if (d->floorstyle < 2)
		d->floorstyle++;
	else
		d->floorstyle = 0;
}

/*
** Swaps between the different fog settings.
*/

void			switch_fog(t_doom *d)
{
	d->fog++;
	if (d->fog == 4)
		d->fog = 0;
}
