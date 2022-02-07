/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 16:41:55 by qbenaroc          #+#    #+#             */
/*   Updated: 2020/08/01 18:07:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	exit_error(t_doom *e)
{
	free_map(&e->map);
	exit(0);
}

int		display_error(t_doom *e, char *reason)
{
	ft_putendl(reason);
	exit_error(e);
	return (0);
}
