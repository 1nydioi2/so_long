/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:33:57 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/23 22:38:35 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chest_count(char **map, int height)
{
	int	chest;
	int	h;
	int	w;

	h = 0;
	chest = 0;
	while (++h < (height - 1))
	{
		w = 0;
		while (map[h][++w + 1])
			if (map[h][w] == 'C')
				chest++;
	}
	return (chest);
}

int	fil(char **map, int h, int w, int *flooded)
{
	char	c;
	int		p;

	c = (map[h][w] * (map[h][w] != 'E' && map[h][w] != 'P'));
	p = 0;
	if (map[h - 1][w] == 'E' || map[h - 1][w] == 'P')
		map[h][w] = map[h - 1][w];
	if (map[h + 1][w] == 'E' || map[h + 1][w] == 'P')
	{
		p += (map[h][w] != c && map[h][w] != map[h + 1][w]);
		map[h][w] = map[h + 1][w];
	}
	if (map[h][w - 1] == 'E' || map[h][w - 1] == 'P')
	{
		p += (map[h][w] != c && map[h][w] != map[h][w - 1]);
		map[h][w] = map[h][w - 1];
	}
	if (map[h][w + 1] == 'E' || map[h][w + 1] == 'P')
	{
		p += (map[h][w] != c && map[h][w] != map[h][w + 1]);
		map[h][w] = map[h][w + 1];
	}
	*flooded = ((c == map[h][w] || !c) && *flooded);
	return (p);
}

int	flood(char **map, int height, int bo)
{
	int	h;
	int	w;
	int	pte;
	int	ptc;
	int	*f;

	pte = 0;
	ptc = 0;
	f = &bo;
	while (!*f && (!pte || !ptc))
	{
		*f = 1;
		h = 0;
		ptc = 1;
		while (++h < (height - 1))
		{
			w = 0;
			while (map[h][++w + 1])
			{
				pte += (map[h][w] != '1' && fil(map, h, w, f));
				ptc = ((map[h][w] != 'C') * ptc);
			}
		}
	}
	return (ptc * pte);
}
