/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:19:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/25 01:14:06 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	here_is_the_map(int fd, char ***map, int height)
{
	int	i;

	*map = malloc(sizeof(char *) * height);
	if (*map == NULL)
		return ;
	i = -1;
	while (++i < height)
	{
		(*map)[i] = ft_gnl(fd);
		printf("height = %d strlen = %d, map[%d] = %s\n", height, ft_strlen((*map)[i]), i, (*map)[i]);
		if ((*map)[i] == NULL)
		{
			map_liberator((*map), i + 1);
			return ;
		}
	}
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
			else if (map[i][j] != '0' && map[i][j] != '1')
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
	width = ft_strlen(map[0]);
	while (++i < height && rectangle)
	{
		j = -1;
		if (i == (height - 1) || (!i))
			while (map[i][++j] && rectangle)
				rectangle = (map[i][j] == '1' && j < width);
		else
		{
			rectangle = (map[i][++j] == '1');
			while (map[i][j] && rectangle)
				j++;
			rectangle = (map[i][j - 1] == '1' && (j - 1) < width);
		}
	}
	return (rectangle);
}

int	is_the_map_doable(char **map, int height)
{
	int	res;
	int	bo;
	char	**map_cpy;
	int	chest_count_i;

	bo = 0;
	chest_count_i = chest_count(map, height);
	map_cpy = arrstr_cpy(map, height);
	res = flood(map_cpy, height, bo, chest_count_i);
	map_liberator(map_cpy, height);
	return (res);
}

int	is_there_a_map_issue(char *name, char ***map, int height)
	
{
	int	map_fd;
	int	issue;

	issue = 0;
	map_fd = open(name, O_RDONLY);
	here_is_the_map(map_fd, map, height);
	if (map_fd <= 0 && ++issue)
		perror("encountered an error while trying to open the map : ");
	else if (map == NULL && ++issue)
		perror("encountered an error while allocating the map : ");
	else if (!is_every_char_compliant(*map, height) && ++issue)
		write(1, "map is non-compilant\n", 21);
	else if (!is_the_map_rectangular(*map, height) && ++issue)
		write(1, "map is not rectangular\n", 23);
	else if (!is_the_map_doable(*map, height) && ++issue)
		write(1, "the player can't finish the game on this map\n", 45);
	close(map_fd);
	if (map != NULL && issue)
		map_liberator(*map, height);
	return (issue);
}
