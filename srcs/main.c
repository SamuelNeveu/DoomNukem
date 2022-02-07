/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:47:19 by saneveu           #+#    #+#             */
/*   Updated: 2020/08/01 17:56:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

int				check_dotdoom(char *str)
{
	int i;

	i = ft_strlen(str);
	if (!ft_strequ((str + i - 5), ".doom"))
		return (0);
	else
		return (1);
}

void			display_map(t_map map)
{
	int i;
	int j;

	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			ft_putnbr(map.map[i][j]);
		}
		ft_putchar('\n');
	}
}

int				main(int argc, char **argv)
{
	t_doom	data;

	if (argc != 2)
		return (0);
	if (!check_dotdoom(argv[1]))
	{
		ft_putendl("doom-nukem: not valid format\nuse .doom file");
		return (0);
	}
	ft_memset(&data, 0, sizeof(t_doom));
	data.strgame = argv[1];
	if (!parse(&data, data.strgame))
		clean_exit(&data, "doom-nukem: map error (parse error)", 0);
	init_sdl(&data);
	init_menu(&data);
	init_forge(&data);
	init_data(&data);
	load_datagame(&data);
	while (1)
		(data.player.f[data.player.platform])((void *)&data);
	clean_exit(&data, "END OF GAME\n", 0);
	return (0);
}
