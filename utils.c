/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:50:47 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 18:42:43 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fline_count(char *name)
{
	int		lc[2];
	char	buff[42];
	int		i;
	int		rv;
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 1)
		return (-1);
	lc[0] = 0;
	lc[1] = 0;
	rv = read(fd, buff, 42);
	while (rv > 0)
	{
		i = 0;
		while (i < rv)
		{
			lc[0] += ((buff[i] && buff[i] != '\n') && (!lc[1]++));
			lc[1] = (buff[i++] != '\n');
		}
		rv = read(fd, buff, 42);
	}
	close(fd);
	return (lc[0]);
}

int	ft_strlen(char *str)
{
	int	res;

	res = 0;
	while (str && str[res])
		res++;
	return (res);
}

void	map_liberator(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
	return ;
}

char	**arrstr_cpy(char **map, int height)
{
	char	**map_cpy;
	int		i;
	int		j;

	i = 0;
	map_cpy = NULL;
	map_cpy = malloc(sizeof(char *) * height);
	if (map_cpy == NULL)
		return (NULL);
	while (i < height)
	{
		j = -1;
		map_cpy[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (map_cpy[i] == NULL)
			return (map_liberator(map_cpy, (i + 1)), NULL);
		while (map[i][++j])
			map_cpy[i][j] = map[i][j];
		map_cpy[i][j] = '\0';
		i++;
	}
	return (map_cpy);
}

char	*ft_strjoin(char *start, char *end)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(start) + ft_strlen(end) + 1));
	if (res == NULL)
		return (NULL);
	while (start && start[i])
		res[j++] = start[i++];
	i = 0;
	while (end && end[i])
		res[j++] = end[i++];
	res[j] = '\0';
	free(start);
	free(end);
	return (res);
}
