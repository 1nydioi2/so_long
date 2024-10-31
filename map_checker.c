/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:19:26 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 21:13:29 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	here_is_the_map(int fd, char ***map, int height)
{
	int	i;

	*map = malloc(sizeof(char *) * height);
	if (*map == NULL)
		return (1);
	i = -1;
	while (++i < height)
	{
		(*map)[i] = ft_gnl(fd);
		if ((*map)[i] == NULL)
		{
			map_liberator((*map), i + 1);
			write(1, "Error\nmap creation failed\n", 27);
			return (1);
		}
	}
	return (0);
}

int	is_every_char_compliant(char **map, int height)
{
	int	i[2];
	int	exit;
	int	chest;
	int	player;

	i[0] = -1;
	player = 0;
	exit = 0;
	chest = 0;
	while (++i[0] < height && (player < 2 && exit < 2))
	{
		i[1] = -1;
		while (map[i[0]][++i[1]] && (player < 2 && exit < 2))
		{
			if (map[i[0]][i[1]] == 'C')
				chest++;
			else if (map[i[0]][i[1]] == 'P')
				player++;
			else if (map[i[0]][i[1]] == 'E')
				exit++;
			else if (map[i[0]][i[1]] != '0' && map[i[0]][i[1]] != '1')
				return (0);
		}
	}
	return ((chest) && ((player == 1) && (exit == 1)));
}

int	is_the_map_rectangular(char **map, int height)
{
	int	i;
	int	j;
	int	width;
	int	rectangle;

	i = -1;
	width = ft_strlen(map[0]);
	rectangle = (width == ft_strlen(map[height - 1]));
	j = -1;
	while (++i < height && rectangle)
	{
		j = -1;
		if ((!i) || i == (height - 1))
			while (map[i][++j] && rectangle)
				rectangle = (map[i][j] == '1' && j < width);
		else
		{
			rectangle = (map[i][++j] == '1');
			while (map[i][j] && rectangle)
				j++;
			rectangle = ((rectangle && j) && (j == width
						&& map[i][j - 1] == '1'));
		}
	}
	return (rectangle);
}

int	is_the_map_doable(char **map, int height)
{
	int		res;
	int		bo;
	char	**map_cpy;

	bo = 0;
	map_cpy = arrstr_cpy(map, height);
	res = flood(map_cpy, height, bo);
	map_liberator(map_cpy, height);
	return (res);
}

int	is_there_a_map_issue(char *name, char ***map, int height)
{
	int	map_fd;
	int	issue;

	issue = 0;
	map_fd = open(name, O_RDONLY);
	if (here_is_the_map(map_fd, map, height))
		return (1);
	if (map_fd <= 0 && ++issue)
		perror("Error\nencountered an error while trying to open the map : ");
	else if (map == NULL && ++issue)
		perror("Error\nencountered an error while allocating the map : ");
	else if (!is_the_map_rectangular(*map, height) && ++issue)
		write(1, "Error\nmap is not rectangular\n", 30);
	else if (!is_every_char_compliant(*map, height) && ++issue)
		write(1, "Error\nsome map characters are non-compilant\n", 44);
	else if (!is_the_map_doable(*map, height) && ++issue)
		write(1, "Error\nthe player can't finish the game on this map\n", 51);
	close(map_fd);
	if (map != NULL && issue)
		map_liberator(*map, height);
	return (issue);
}
