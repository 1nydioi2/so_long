/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:44:39 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 20:14:04 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_pos(t_game *game, int h, int w)
{
	if (game->map[h][w] == 'C')
		game->player.opened_chests++;
	game->map[game->player.h][game->player.w] = '0';
	game->player.h = h;
	game->player.w = w;
	game->map[game->player.h][game->player.w] = 'P';
	game->player.steps++;
	print_steps(game->player.steps);
	game->player.steps++;
	return ;
}

int	right_is_right(t_game *game, char **map, int h, int w)
{
	int	nph;
	int	npw;

	nph = -1;
	npw = 0;
	if (map[h - 1][w] != '1' && map[h][w + 1] == 'P')
		return (update_player_pos(game, (h - 1), w), 1);
	if (map[h][w + 1] != '1' && map[h + 1][w] == 'P')
		return (update_player_pos(game, h, (w + 1)), 1);
	else if (map[h][w + 1] != '1' && map[h][w + 1] != 'P')
		nph += (++npw);
	if (map[h + 1][w] != '1' && map[h][w - 1] == 'P')
		return (update_player_pos(game, (h + 1), w), 1);
	else if (map[h + 1][w] != '1' && map[h + 1][w] != 'P')
		nph += ((nph < 0) + (!npw || npw--));
	if (map[h][w - 1] != '1' && map[h - 1][w] == 'P')
		return (update_player_pos(game, h, (w - 1)), 1);
	else if (map[h - 1][w] != '1' && map[h + 1][w] == 'P')
		return (update_player_pos(game, (h - 1), w), 1);
	else if (map[h][w - 1] != '1' && map[h][w - 1] != 'P')
		return (update_player_pos(game, h, (w - 1)), 1);
	if ((!npw && nph == -1) && map[h - 1][w] == '1')
		return (0);
	return (update_player_pos(game, (h + nph), (w + npw)), 1);
}

int	is_extension_okay(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i < 4)
		return (0);
	if (str[--i] != 'r')
		return (0);
	if (str[--i] != 'e')
		return (0);
	if (str[--i] != 'b')
		return (0);
	if (str[--i] != '.')
		return (0);
	if (str[--i] == '/')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*map_name;
	char	**map;
	int		height;
	t_game	game;

	if (argc != 2)
		return (write(1, "Error\nwrong argument account\n", 29));
	map_name = argv[1];
	if (!is_extension_okay(map_name))
		return (write(1, "Error\nmap extension is not .ber\n", 32));
	height = fline_count(map_name);
	if (height == -1)
		return (write(1, "Error\ncouldn't open the map\n", 28));
	if (height < 3)
		return (write(1, "Error\nmap is not big enough\n", 28));
	if (is_there_a_map_issue(map_name, &map, height))
		return (1);
	game_initializer(&game, map, height);
	if (mlx_starter(&game))
		return (map_liberator(map, height), 1);
	image_initializer(&game);
	mlx_refresh_whole_frame(&game);
	mlx_handler(&game);
}
