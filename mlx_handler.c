/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:45 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 19:56:31 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	mlx_player_refresh_y(t_game *game, int *last_y, int	*plr_r_y)
{
	if (game->player.h > (game->m_height / 2))
	{
		*plr_r_y = game->images.offset_y + (game->images.size
				* (game->images.range_y - (game->m_height - game->player.h)));
		*last_y = game->images.offset_y + (game->images.size
				* (game->images.range_y - (game->m_height - *last_y)));
	}
	else
	{
		*plr_r_y = game->images.offset_y + (game->images.size * game->player.h);
		*last_y = game->images.offset_y + (game->images.size * *last_y);
	}
}

void	mlx_player_refresh_x(t_game *game, int *last_x, int *plr_r_x)
{
	if (game->player.w > (game->m_width / 2))
	{
		*plr_r_x = game->images.offset_x + (game->images.size
				* (game->images.range_x - (game->m_width - game->player.w)));
		*last_x = game->images.offset_x + (game->images.size
				* (game->images.range_x - (game->m_width - *last_x)));
	}
	else
	{
		*plr_r_x = game->images.offset_x + (game->images.size * game->player.w);
		*last_x = game->images.offset_x + (game->images.size * *last_x);
	}
}

void	mlx_handler(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 0, &mlx_closing, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_redirector, game);
	mlx_loop(game->mlx_dspl);
}

int	mlx_closing(t_game *game)
{
	mlx_destroy_window(game->mlx_dspl, game->mlx_win);
	mlx_destroy_image(game->mlx_dspl, game->images.player);
	mlx_destroy_image(game->mlx_dspl, game->images.exit);
	mlx_destroy_image(game->mlx_dspl, game->images.ground);
	mlx_destroy_image(game->mlx_dspl, game->images.wall);
	mlx_destroy_image(game->mlx_dspl, game->images.collectable);
	map_liberator(game->map, game->m_height);
	mlx_destroy_display(game->mlx_dspl);
	print_steps(game->player.steps);
	free(game->mlx_dspl);
	exit(0);
}

int	mlx_starter(t_game *game)
{
	game->mlx_dspl = mlx_init();
	if (game->mlx_dspl == NULL)
	{
		perror("encountered an error while creating display : ");
		return (1);
	}
	mlx_get_screen_size(game->mlx_dspl, &game->s_width, &game->s_height);
	game->mlx_win = mlx_new_window
		(game->mlx_dspl, game->s_width, game->s_height, "so_long");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx_dspl);
		perror("encountered an error while creating window : ");
		return (1);
	}
	return (0);
}
