/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:42 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/26 00:17:18 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	map_dater(int data[3], char **map, int height)
{
	int	h;
	int	w;

	h = 0;
	data[2] = 0;
	while (++h < (height - 1)) 
	{
		w = 0;
		while (map[++w + 1])
		{
			if (map[h][w] == 'C')
				data[2]++;
			else if (map[h][w] == 'P')
			{
				data[0] = h;
				data[1] = w;
			}
		}
	}
}

void	game_initializer(t_game *game, char **map, int height)
{
	int	map_data[3];
	t_icon	icons;
	t_plr	player;

	game->map = map;
	game->height = height;
	map_dater(map_data, map, height);
	player.steps = 0;
	player.opened_chests = 0;
	player.h = map_data[0];
	player.w = map_data[1];
	game->chest_amount = map_data[2];
	game->player = player;
	icons.player_icon = "/icons/player.xpm";
	icons.walls_icon = "/icons/walls.xpm";
	icons.exit_icon = "/icons/exit.xpm";
	icons.ground_icon = "/icons/ground.xpm";
	icons.collectables_icon = "/icons/collectables.xpm";
	game->icons = icons;
}
