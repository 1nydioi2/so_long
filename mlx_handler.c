/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:45 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/26 01:55:51 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	mlx_handler(t_game *game)
{
	//void	*image;

	//image = mlx_new_image(game->mlx_dspl, 860, 1280);
	//printf("mlx_handler\tgamex = %p, display = %p, window = %p\n", game, game->mlx_dspl, game->mlx_win);
	mlx_hook(game->mlx_win, 2, 1L<<0, &mlx_closing, game);
	mlx_loop(game->mlx_dspl);
}

int	mlx_closing(int keycode, t_game *game)
{
	(void)keycode;
	//printf("gamex = %p\n", game);
	//printf("display = %p\n", game->mlx_dspl);
//	printf("window = %p\n", game->mlx_win);
	mlx_destroy_window(game->mlx_dspl, game->mlx_win);
	map_liberator(game->map, game->height);
	mlx_destroy_display(game->mlx_dspl);
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
	game->mlx_win = mlx_new_window(game->mlx_dspl, 1260, 820, "so_long");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx_dspl);
		perror("encountered an error while creating window : ");
		return (1);
	}
	//printf("mlx_starter\tgamex = %p, display = %p, window = %p\n", game, game->mlx_dspl, game->mlx_win);
	return (0);
}
