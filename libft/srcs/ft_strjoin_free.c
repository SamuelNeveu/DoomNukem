/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:26:24 by qbenaroc          #+#    #+#             */
/*   Updated: 2020/06/23 19:14:02 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin_free(const char *s1, const char *s2, int n)
{
	char *res;

	res = NULL;
	if (!(res = ft_strjoin(s1, s2)))
		return (NULL);
	if (n == 1)
		free((char*)s1);
	else if (n == 2)
		free((char*)s2);
	else if (n == 3)
	{
		free((char*)s1);
		free((char*)s2);
	}
	return (res);
}
