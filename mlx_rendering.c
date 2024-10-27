/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:12:54 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/27 02:47:02 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	mlx_frame_refresh(t_game *game, char direction)
{
	int	w;
	int	h;
	int	i;

	(void)direction;
        printf("frame_refresh\tplayer_image = %p\n", game->images.player_image);
	h = 0;
	w = 0;
	i = 0;
	while (i++ < 11)
	{
		mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.ground_image, w, h);
		w += 166;
	}
	w = 0;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.player_image, w, h);
	w += 166;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.collectable_image, w, h);
	w += 166;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.exit_image, w, h);
	w += 166;
	i = 0;
	while (i++ < 6)
	{
		mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.ground_image, w, h);
		h += 166;
	}
	/*h += 165;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.player_image, w, h);
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.ground_image, w, h);
	h = 0;
	w = 300;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.ground_image, w, h);
	w = 450;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.wall_image, w, h);
	w = 600;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.exit_image, w, h);
	w = 750;
	mlx_put_image_to_window(game->mlx_dspl, game->mlx_win, game->images.collectable_image, w, h);
	w = 900;*/
}
