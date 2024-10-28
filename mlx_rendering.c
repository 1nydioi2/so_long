/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:12:54 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/28 02:16:28 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	wall_in_range(t_game *game, char d, int x, int y)
{
	if ((game->player.w + (game->range_x / 2)) > game->m_width)
		return (mlx_refresh_player(game, x, y), 1);	
	else if ((game->player.w - (game->range_x / 2)) < 0)
		return (mlx_refresh_player(game, x, y), 1);	
	else if ((game->player.h - (game->range_y / 2)) < 0)
		return (mlx_refresh_player(game, x, y), 1);	
	else if ((game->player.h + (game->range_y / 2)) > game->m_height)
		return (mlx_refresh_player(game, x, y), 1);
	else
		return (0);
}

void	mlx_refresh_player(t_game *game, int last_x, int last_y)
{
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.player_image, game->player.x, game->player.y);
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.ground_image, lox, loy); 
}

void	*wotp(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == '0')
		return (game->images.ground_image);
	else if (map[y][x] == '1')
		return (game->images.wall_image);
	else if (map[y][x] == 'C')
		return (game->images.collectable_image);
	else if (map[y][x] == 'P')
		return (game->images.player_image);
	else
		return (game->images.exit_image);
}

void	mlx_refresh_whole_frame(t_game *game)
{
	int	h;
	int	w;
	int	lox;
	int	loy;

        printf("frame_refresh\tplayer_image = %p\n", game->images.player_image);
	lox = game->images.offset_x;
	loy = game->images.offset_y;
	h = (game->player.h - (game->range_y / 2));
	while (h <= ((game->player.h + (game->range_y / 2) + 1)))
	{
		lox = game->images.offset_x;
		w = (game->player.w - (game->range_x / 2));
		while (w <= ((game->player.w + (game->range_x / 2) + 1)))
		{
			mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, wotp(game->map, w, h, game), lox, loy);
			lox += game->images.size;
		}
		loy += game->images.size;
		h++;
	}
}
