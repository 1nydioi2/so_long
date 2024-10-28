/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:56:42 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/28 01:45:23 by nilamber         ###   ########.fr       */
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

	height = 0;
	images.size = 166;
	images.player_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/player.xpm", &width, &height);
	images.wall_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/wall.xpm", &width, &height);
	images.exit_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/exit.xpm", &width, &height);
	images.ground_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/ground.xpm", &width, &height);
	images.collectable_image = mlx_xpm_file_to_image(game->mlx_dspl, "sprites/collectable.xpm", &width, &height);
 	images.range_x = (game->s_width / images.size);
	images.range_x -= ((game->m_width < images.range_x) * (images.range_x - game->m_width));
 	images.range_y = (game->s_height / images.size);
	images.range_y -= ((game->m_height < images.range_y) * (images.range_y - game->m_height));
	images.offset_x = ((game->s_width % images.size) / 2);
        images.offset_y = ((game->s_height % images.size) / 2);
        if (game->m_width < images.range_x)
                images.offset_x += ((((game->s_width % images.size) - game->m_width) * images.size) / 2);
        if (game->m_height < images.range_y)
                images.offset_y += ((((game->s_height % images.size) - game->m_height) * images.size) / 2);	
	game->images = images;
	printf("image width = %d, height = %d\n", width, height);
}

void	game_initializer(t_game *game, char **map, int height)
{
	int	map_data[3];
	t_plr	player;

	game->map = map;
	game->m_height = height;
	game->m_width = ft_strlen(game->map[0]);
	map_dater(map_data, map, height);
	player.steps = 0;
	player.opened_chests = 0;
	player.h = map_data[0];
	player.w = map_data[1];
	game->chest_amount = map_data[2];
	game->player = player;
}
