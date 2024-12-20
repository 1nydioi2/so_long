/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:12:54 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 19:58:49 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	wall_in_range(t_game *game)
{
	int	wall_in_x_range;
	int	wall_in_y_range;

	wall_in_x_range = 0;
	wall_in_y_range = 0;
	if ((game->player.w + (game->images.range_x / 2)) > game->m_width)
		wall_in_x_range = 1;
	else if ((game->player.w - (game->images.range_x / 2)) < 0)
		wall_in_x_range = 1;
	if ((game->player.h - (game->images.range_y / 2)) < 0)
		wall_in_y_range = 1;
	else if ((game->player.h + (game->images.range_y / 2)) > game->m_height)
		wall_in_y_range = 1;
	return (wall_in_x_range + wall_in_y_range);
}

void	mlx_refresh_player(t_game *game, int last_x, int last_y)
{
	int	plr_r_x;
	int	plr_r_y;

	mlx_player_refresh_y(game, &last_y, &plr_r_y);
	mlx_player_refresh_x(game, &last_x, &plr_r_x);
	mlx_put_image_to_window
		(game->mlx_dspl, game->mlx_win, game->images.player, plr_r_x, plr_r_y);
	mlx_put_image_to_window
		(game->mlx_dspl, game->mlx_win, game->images.ground, last_x, last_y);
	return ;
}

void	*wotp(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == '0')
		return (game->images.ground);
	else if (map[y][x] == '1')
		return (game->images.wall);
	else if (map[y][x] == 'C')
		return (game->images.collectable);
	else if (map[y][x] == 'P')
		return (game->images.player);
	else if (game->player.opened_chests == game->chest_amount)
		return (game->images.exit_opened);
	else
		return (game->images.exit_closed);
}

void	camera_range_init(t_game *game, int (*h)[3], int (*w)[3])
{
	if ((game->player.h - (game->images.range_y / 2)) <= 0)
		(*h)[0] = 0;
	else if ((game->player.h + (game->images.range_y / 2)) >= game->m_height)
		(*h)[0] = (game->m_height - game->images.range_y);
	else
		(*h)[0] = (game->player.h - (game->images.range_y / 2));
	(*h)[1] = ((*h)[0] + game->images.range_y);
	if ((game->player.w - (game->images.range_x / 2)) <= 0)
		(*w)[0] = 0;
	else if ((game->player.w + (game->images.range_x / 2)) >= game->m_width)
		(*w)[0] = (game->m_width - game->images.range_x);
	else
		(*w)[0] = (game->player.w - (game->images.range_x / 2));
	(*w)[1] = ((*w)[0] + game->images.range_x);
	return ;
}

void	mlx_refresh_whole_frame(t_game *game)
{
	int	h[3];
	int	w[3];
	int	lox;
	int	loy;

	lox = game->images.offset_x;
	loy = game->images.offset_y;
	camera_range_init(game, &h, &w);
	h[2] = h[0];
	while (h[2] < h[1])
	{
		lox = game->images.offset_x;
		w[2] = w[0];
		while (w[2] < w[1])
		{
			mlx_put_image_to_window(game->mlx_dspl, game->mlx_win,
				wotp(game->map, w[2], h[2], game), lox, loy);
			lox += game->images.size;
			w[2]++;
		}
		loy += game->images.size;
		h[2]++;
	}
	return ;
}
