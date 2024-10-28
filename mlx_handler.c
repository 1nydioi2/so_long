/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:32:45 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/27 23:59:32 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	mlx_handler(t_game *game)
{
	//void	*image;

	//image = mlx_new_image(game->mlx_dspl, 860, 1280);
	//printf("mlx_handler\tgamex = %p, display = %p, window = %p\n", game, game->mlx_dspl, game->mlx_win);
	mlx_hook(game->mlx_win, 2,1L<<0, &key_redirector, game);
	mlx_loop(game->mlx_dspl);
}

int	mlx_closing(t_game *game)
{
	//printf("gamex = %p\n", game);
	//printf("display = %p\n", game->mlx_dspl);
	//printf("window = %p\n", game->mlx_win);
	mlx_destroy_window(game->mlx_dspl, game->mlx_win);
	map_liberator(game->map, game->m_height);
	mlx_destroy_display(game->mlx_dspl);
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
	printf("screen size = %d * %d\t/6 = %d * %d\n", game->s_width, game->s_height, (game->s_width / 6), (game->s_height / 6));
	game->mlx_win = mlx_new_window(game->mlx_dspl, game->s_width, game->s_height, "so_long");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx_dspl);
		perror("encountered an error while creating window : ");
		return (1);
	}
	//printf("mlx_starter\tgamex = %p, display = %p, window = %p\n", game, game->mlx_dspl, game->mlx_win);
	return (0);
}
