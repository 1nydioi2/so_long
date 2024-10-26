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
	mlx_loop(game->mlx_dspl);
}

void	mlx_closing(void *mlx_dspl, void *mlx_win)
{
	mlx_destroy_window(mlx_dspl, mlx_win);	
	mlx_destroy_display(mlx_dspl);
}

int	mlx_starter(t_game *game)
{
	game->mlx_dspl = mlx_init();
	if (game->mlx_dspl == NULL)
	{
		perror("encountered an error while creating display : ");
		return (1);
	}
	game->mlx_win = mlx_new_window(game->mlx_dspl, 420, 420, "so_long");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx_dspl);
		perror("encountered an error while creating window : ");
		return (1);
	}
	return (0);
}
