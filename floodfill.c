/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:33:57 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/18 02:56:59 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_chest_found(char **map)
{
	int	h;
	int	w;
	int	chest;

	h = 0;
	chest = 0;
	while (++h < (height - 1))
	{
		w = 0;
		while (map[h][++w + 1])
		{
			if (map[h + 1][w] == 'E' || map[h - 1][w] == 'P')
				chest++;
			else if (map[h - 1][w] == 'E' || map[h + 1][w] == 'P')
				chest++;
			else if (map[h][w + 1] == 'E' || map[h][w + 1] == 'P')
				chest++;
			else if (map[h][w - 1] == 'E' || map[h][w - 1] == 'P')
				chest++;
		}
	}
	return (chest_count(map) == chest);
}

int	chest_count(char **map, int height);
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

int	fill(char ***map, int h, int w, int *flooded)
{
	char	c;
	int	p;

	c = map[h][w];
	p = 0;
	if ((*map)[h - 1][w] == 'E' || (*map)[h - 1][w] == 'P')
		(*map)[h][w] = (*map)[h - 1][w];
	if ((*map)[h + 1][w] == 'E' || (*map)[h + 1][w] == 'P')
	{
		p += ((*map)[h][w] != '0' && (*map)[h][w] != (*map)[h + 1][w])
		(*map)[h][w] = (*map)[h + 1][w];
	}
	if ((*map)[h][w - 1] == 'E' || (*map)[h][w - 1] == 'P')
	{
		p += ((*map)[h][w] != '0' && (*map)[h][w] != (*map)[h][w - 1])
		(*map)[h][w] = (*map)[h][w - 1];
	}
	if ((*map)[h][w + 1] == 'E' || (*map)[h][w + 1] == 'P')
	{
		p += ((*map)[h][w] != '0' && (*map)[h][w] != (*map)[h][w + 1])
		(*map)[h][w] = (*map)[h][w + 1];
	}
	*flooded = (c == map[h][w] || *flooded);
	return (p);
}

int	flood(char **map, int height)
{
	int	h;
	int	w;
	int	player_to_exit;
	int	player_to_chest;
	int	*f;

	h = 0;
	chest_count = chest_count(map, height);
	player_to_exit = 0;
	*f = 0;
	while (!*f && !player_to_chest)
	{
		*f = 0;
		while (++h < height)
		{
			w = -1;
			while (map[h][++w])
				if (map[h][w] == '0' && fill(&map, h, w, f))
					player_to_exit++;
		}
		player_to_chest = (player_to_exit && all_chest_found(map));
	}
	return (player_to_chest * player_to_exit);
}
