/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:44:39 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/26 01:54:33 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_extension_okay(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 5)
		return (0);
	if (i >= 0 && str[--i] != 'r')
		return (0);
	if (i >= 0 && str[--i] != 'e')
		return (0);
	if (i >= 0 && str[--i] != 'b')
		return (0);
	if (i >= 0 && str[--i] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*map_name;
	char	**map;
	int	height;
	t_game	game;

	if (argc != 2)
		return (1);
	map_name = argv[1];
	if (!is_extension_okay(map_name))
		return (1);
	height = fline_count(map_name);
	if (height < 3)
		return (1);
	if (is_there_a_map_issue(map_name, &map, height))
		return (1);
	printf("map all good\n");
	game_initializer(&game, map, height);
	if (mlx_starter(&game))
		return (map_liberator(map, height), 1);
	image_initializer(&game);
	mlx_handler(&game);
}
