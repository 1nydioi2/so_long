/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:19:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/18 03:01:32 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	here_is_the_map(int fd, char **map)
{
	int	height;
	int	i;

	height = line_number(fd);
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (0);
	i = -1;
	while (++i < height)
	{
		map[i] = ft_getline(fd);
		if (map[i] == NULL)
		{
			map_liberator(map, i);
			return (0);
		}
	}
	map[i] = NULL;
	return (height);
}

int	is_every_char_compliant(char **map, int height)
{
	int	i;
	int	j;
	int	exit;
	int	chest;
	int	player;

	i = -1;
	player = 0;
	exit = 0;
	chest = 0;
	while (++i < height && (player < 2 && exit < 2))
	{
		j = -1;
		while (map[i][++j] && (player < 2 && exit < 2))
		{
			if (map[i][j] == 'C')
				chest++;
			else if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] != '0' || map[i][j] != '1')
				return (0);
		}
	}
	return (((chest) + (player == 1) + (exit == 1)) / 3);
}

int	is_the_map_rectangular(char **map, int height)
{
	int	i;
	int	j;
	int	width;
	int	rectangle;

	i = -1;
	rectangle = 1;
	width = ft_strlen(map[i]);
	while (++i < height && rectangle)
	{
		j = 0;
		if (i == (height - 1) || (!i))
			while (map[i][j] && rectangle)
				rectangle = (map[i][j++] == '1' && j < width)
		else
		{
			rectangle = (map[i][j] == '1')
			while (map[i][j] && rectangle)
				j++;
			rectangle = (map[i][j - 1] == '1' && (j - 1) < width);
		}
	}
	return (rectangle);
}

int	is_the_map_doable(char **map, int height)
{
		

}

int	is_there_a_map_issue(char *name, char **map)
{
	int	map_fd;
	int	issue;
	int	height;

	issue = 0;
	map_fd = open(name, O_RDONLY);
	if (map_fd <= 0 && ++issue)
		perror("encountered an error while trying to open the map : ");
	height = here_is_the_map(map_fd, map);
	else if (map == NULL)
		perror("encountered an error while allocating the map : ");
	else if (!is_every_char_compilant(map, height))
		perror("map is non-compilant\n");
	else if (!is_the_map_rectangular(map, height)
		perror("map is not rectangular\n");
	else if (!is_the_map_doable(map, height))
		perror("map does not allow the player to finish the game\n");
	close(fd);
	if (map != NULL && issue)
		map_liberator(map);
	return (issue);
}
