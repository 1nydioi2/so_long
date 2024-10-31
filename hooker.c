/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:23:01 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/30 18:57:20 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	move_up(t_game *game)
{
	int	ph;
	int	pw;

	ph = game->player.h;
	pw = game->player.w;
	if (game->map[ph - 1][pw] == '1')
		return (0);
	if (game->map[ph - 1][pw] == 'C')
		game->player.opened_chests++;
	else if (game->map[ph - 1][pw] == 'E')
	{
		if (game->player.opened_chests == game->chest_amount)
			return (game->player.steps++, mlx_closing(game));
		else if (right_is_right(game, game->map, (ph - 1), pw))
			return (1);
		else
			return (0);
	}
	game->player.steps++;
	ph--;
	game->map[ph][pw] = 'P';
	return (1);
}

int	move_down(t_game *game)
{
	int	ph;
	int	pw;

	ph = game->player.h;
	pw = game->player.w;
	if (game->map[ph + 1][pw] == '1')
		return (0);
	if (game->map[ph + 1][pw] == 'C')
		game->player.opened_chests++;
	else if (game->map[ph + 1][pw] == 'E')
	{
		if (game->player.opened_chests == game->chest_amount)
			return (game->player.steps++, mlx_closing(game));
		else if (right_is_right(game, game->map, (ph + 1), pw))
			return (1);
		else
			return (0);
	}
	game->player.steps++;
	ph++;
	game->map[ph][pw] = 'P';
	return (1);
}

int	move_left(t_game *game)
{
	int	ph;
	int	pw;

	ph = game->player.h;
	pw = game->player.w;
	if (game->map[ph][pw - 1] == '1')
		return (0);
	if (game->map[ph][pw - 1] == 'C')
		game->player.opened_chests++;
	else if (game->map[ph][pw - 1] == 'E')
	{
		if (game->player.opened_chests == game->chest_amount)
			return (game->player.steps++, mlx_closing(game));
		else if (right_is_right(game, game->map, ph, (pw - 1)))
			return (1);
		else
			return (0);
	}
	game->player.steps++;
	pw--;
	game->map[ph][pw] = 'P';
	return (1);
}

int	move_right(t_game *game)
{
	int	ph;
	int	pw;

	ph = game->player.h;
	w = game->player.w;
	if (game->map[ph][pw + 1] == '1')
		return (0);
	if (game->map[ph][pw + 1] == 'C')
		game->player.opened_chests++;
	else if (game->map[ph][pw + 1] == 'E')
	{
		if (game->player.opened_chests == game->chest_amount)
			return (game->player.steps++, mlx_closing(game));
		else if (right_is_right(game, game->map, ph, (pw + 1)))
			return (1);
		else
			return (0);
	}
	game->player.steps++;
	pw++;
	game->map[ph][pw] = 'P';
	return (1);
}

int	key_redirector(int keynum, t_game *game)
{
	int	last[2];
	int	moved;

	last[0] = game->player.w;
	last[1] = game->player.h;
	if (keynum == ESC_KEY)
		return (mlx_closing(game));
	else if ((keynum == W_KEY || keynum == W_LC_KEY) || ((keynum == Z_KEY
				|| keynum == Z_LC_KEY) || keynum == UA_KEY))
		moved = move_up(game);
	else if ((keynum == S_KEY || keynum == S_LC_KEY) || keynum == DA_KEY)
		moved = move_down(game);
	else if ((keynum == A_KEY || keynum == A_LC_KEY) || ((keynum == Q_KEY
				|| keynum == Q_LC_KEY) || keynum == LA_KEY))
		moved = move_left(game);
	else if ((keynum == D_KEY || keynum == D_LC_KEY) || keynum == RA_KEY)
		moved = move_right(game);
	else
		return (0);
	if (!moved)
		return (0);
	print_steps(game->player.steps);
	if (wall_in_range(game) == 2)
		return (mlx_refresh_player(game, last[0], last[1]), 0);
	return (mlx_refresh_whole_frame(game), 0);
}
