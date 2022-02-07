/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 19:08:34 by saneveu           #+#    #+#             */
/*   Updated: 2020/07/28 17:00:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "doom.h"

# define ERROR_ARG "Not enough arguments\nUsage : ./doom3d [map_file]"
# define ERROR_MALLOC "Malloc Error"
# define ERROR_PLAYER "No Player id on map [ 2 ]"
# define ERROR_WALL "Map is not surrounded by walls"
# define ERROR_WIN "No Win id on map [ 14 ]"
# define ERROR_OPEN "File opening failed :/\nor\nWrong file name"
# define ERROR_LIST "File not allowed\nor\nLines have not the same length :/"
# define ERROR_MAP "Lines have not the same length\nor\nMap Stocking failed :/"
# define ERROR_CLOSE "Fail to close the file :/"

# define WALL 1
# define PLAYER 2
# define PLANT 3
# define CAGE 4
# define TABLE 5
# define SPAWNER 6
# define WIN 14

#endif
