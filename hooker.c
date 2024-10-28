/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:23:01 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/28 01:42:21 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	move_up(t_game *game)
{
	if (game->map[game->player.h - 1][game->player.w] != '1')
	{	
		if (game->map[game->player.h - 1][game->player.w] == 'C')
		{
			game->player.opened_chests++;
			game->map[game->player.h - 1][game->player.w] = '0';
		}
		else if (game->map[game->player.h - 1][game->player.w] == 'E')
		{			
			if (game->player.opened_chests == game->chest_amount)
				return (game->player.steps++, (void)mlx_closing(game));
			else if (game->map[game->player.h - 2][game->player.w] != '1')
			{
				game->player.steps++;
				game->player.h--;
				return ((void)move_up(game));
			}
			else
				return ;
		}
		game->player.steps++;
		game->player.h--;
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player.h + 1][game->player.w] != '1')
	{	
		if (game->map[game->player.h + 1][game->player.w] == 'C')
		{
			game->player.opened_chests++;
			game->map[game->player.h + 1][game->player.w] = '0';
		}
		else if (game->map[game->player.h + 1][game->player.w] == 'E')
		{			
			if (game->player.opened_chests == game->chest_amount)
				return (game->player.steps++, (void)mlx_closing(game));
			else if (game->map[game->player.h + 2][game->player.w] != '1')
			{
				game->player.steps++;
				game->player.h++;
				return ((void)move_down(game));
			}
			else
				return ;
		}
		game->player.steps++;
		game->player.h++;
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player.h][game->player.w - 1] != '1')
	{	
		if (game->map[game->player.h][game->player.w - 1] == 'C')
		{
			game->player.opened_chests++;
			game->map[game->player.h][game->player.w - 1] = '0';
		}
		else if (game->map[game->player.h][game->player.w - 1] == 'E')
		{			
			if (game->player.opened_chests == game->chest_amount)
				return (game->player.steps++, (void)mlx_closing(game));
			else if (game->map[game->player.h][game->player.w - 2] != '1')
			{
				game->player.steps++;
				game->player.w--;
				return ((void)move_left(game));
			}
			else
				return ;
		}
		game->player.steps++;
		game->player.w--;
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player.h][game->player.w + 1] != '1')
	{	
		if (game->map[game->player.h][game->player.w + 1] == 'C')
		{
			game->player.opened_chests++;
			game->map[game->player.h][game->player.w + 1] = '0';
		}
		else if (game->map[game->player.h][game->player.w + 1] == 'E')
		{			
			if (game->player.opened_chests == game->chest_amount)
				return (game->player.steps++, (void)mlx_closing(game));
			else if (game->map[game->player.h][game->player.w + 2] != '1')
			{
				game->player.steps++;
				game->player.w++;
				return ((void)move_right(game));
			}
			else
				return ;
		}
		game->player.steps++;
		game->player.w++;
	}
}

int	key_redirector(int keynum, t_game *game)
{
	int	last[2];
	char	direction;

	last[0] = game->player.w;
	last[1] = game->player.h;
	printf("keynum = %d\n", keynum);
	if (keynum == ESC_KEY)
		return (mlx_closing(game));
	else if ((keynum == W_KEY || keynum == w_KEY) || ((keynum == Z_KEY || keynum == z_KEY) || keynum == UA_KEY))
	{
		direction = 'u';
		move_up(game);
	}
	else if ((keynum == S_KEY || keynum == s_KEY) ||keynum == DA_KEY)
	{
		direction = 'd';
		move_down(game);
	}
	else if ((keynum == A_KEY || keynum == a_KEY) || ((keynum == Q_KEY || keynum == q_KEY) || keynum == LA_KEY))
	{
		direction = 'l';
		move_left(game);
	}
	else if ((keynum == D_KEY || keynum == d_KEY) || keynum == RA_KEY)
	{	
		direction = 'r';
		move_right(game);
	}
	else
		return (0);
	if (wall_in_range(game, direction, last[0], last[1]))
		return (0);
	return (mlx_refresh_whole_frame(game), 0);
}
