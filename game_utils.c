/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:42 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/27 02:12:54 by nilamber         ###   ########.fr       */
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
		while (map[h][++w + 1])
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

void	image_initializer(t_game *game)
{
	t_image	images;
	int	width;
	int	height;

	width = 0;
	height = 0;
	printf("image_init\tdisplayx = %p\n", game->mlx_dspl);
	images.wall_image = "sprites/wall.xpm";
	images.exit_image = "sprites/exit.xpm";
	images.ground_image = "sprites/ground.xpm";
	images.collectable_image = "sprites/collectable.xpm";
	images.player_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/player.xpm", &width, &height);
	images.wall_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/wall.xpm", &width, &height);
	images.exit_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/exit.xpm", &width, &height);
	images.ground_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/ground.xpm", &width, &height);
	images.collectable_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/collectable.xpm", &width, &height);
	game->images = images;
	printf("image_init\tgplayer_image = %p\n", game->images.player_image);
	printf("image_init\tfplayer_image = %p\n", images.player_image);
}

void	game_initializer(t_game *game, char **map, int height)
{
	int	map_data[3];
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
}
