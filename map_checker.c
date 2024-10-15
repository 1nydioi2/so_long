/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:19:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/15 23:49:51 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**here_is_the_map(int fd)
{

}

int	is_every_char_compliant(char **map)
{

}

int	is_the_map_rectangular(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;
	int	rectangle;

	i = -1;
	rectangle = 1;
	while (map[height] != NULL)
		height++;
	width = ft_strlen(map[i]);
	while (++i < height)
	{
		j = 0;
		if (i == (height - 1) || (!i))
			while (map[i][j])
				rectangle = (map[i][j++] == '1' && j < width)
		else
		{
			rectangle = (map[i][j] == '1')
			while (map[i][j])
				j++;
			rectangle = (map[i][j - 1] == '1' && (j - 1) < width);
		}
	}
	return (rectangle);
}

int	is_the_map_doable(char **map)
{
	
}

int	is_there_a_map_issue(char *name, char **map)
{
	int	map_fd;

	map_fd = open(name, O_RDONLY);
	if (map_fd < 0)
		return (1);
	map = here_is_the_map(map_fd);
	if (map == NULL)
		return (1);
	if (!is_the_map_rectangular(map))
		return (2);
	if (!is_the_map_doable(map))
		return (2);
	return (0)
}
