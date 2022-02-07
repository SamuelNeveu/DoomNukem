/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_threader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:49:23 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/31 20:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

static void		thread_init(t_doom *d, t_thread *t)
{
	int todo;
	int rest;

	t->env = d;
	todo = (W_WIDTH / NB_THREAD);
	rest = (W_WIDTH % NB_THREAD);
	t->start = t->id * todo;
	t->i = t->start - 1;
	t->end = t->start + todo + (t->id == NB_THREAD - 1 ? rest : 0);
	if (pthread_create(&t->thread, NULL, raycasting, (void *)t))
		clean_exit(d, "thread create failed", 0);
}

void			raycast_threader(t_doom *d)
{
	t_thread	thread[NB_THREAD];
	int			i;

	i = -1;
	while (++i < NB_THREAD)
	{
		thread[i].id = i;
		thread_init(d, &thread[i]);
	}
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(thread[i].thread, NULL);
}
