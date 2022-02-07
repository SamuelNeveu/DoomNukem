/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:35:42 by brpinto           #+#    #+#             */
/*   Updated: 2020/08/22 21:26:35 by brpinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		find_name(t_doom *e)
{
	int		len;
	char	**split;
	char	*out;

	out = e->ed.fname;
	while (access(e->ed.fname, F_OK) == 0)
	{
		len = ft_strlen(e->ed.fname);
		if (e->ed.fname[len - 6] < '9')
		{
			e->ed.fname[len - 6] += 1;
			free(e->ed.fname);
		}
		else
		{
			split = ft_strsplit(out, '.');
			out = ft_strjoin_free(split[0], ft_strdup("0"), 3);
			e->ed.fname = ft_strjoin_free(out, ft_strdup(".doom"), 3);
		}
	}
}

static	void	fill_map(t_doom *e, int fd, char *wall)
{
	t_point loop;
	char	*tmp;

	loop.x = -1;
	while (++loop.x < 20)
	{
		loop.y = -1;
		while (++loop.y < 20)
		{
			if ((loop.x == 0 || loop.x == 19) || (loop.y == 0 || loop.y == 19))
				ft_putstr_fd(wall, fd);
			else
			{
				tmp = ft_itoa(e->ed.map[loop.x][loop.y]);
				ft_putstr_fd(tmp, fd);
				free(tmp);
			}
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
	}
	free(wall);
}

int				create_file(t_doom *e, int fd)
{
	int		res;
	char	*wall;

	res = 1;
	wall = ft_itoa(e->ed.wall);
	e->ed.fname = ft_strdup("map/testdoom0.doom");
	find_name(e);
	fd = creat(e->ed.fname, O_CREAT | S_IRUSR | S_IWUSR);
	free(e->ed.fname);
	res = (fd < 0) ? 0 : 1;
	fill_map(e, fd, wall);
	close(fd);
	return (res);
}
