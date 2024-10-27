/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:08:12 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/27 00:26:20 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <bsd/string.h>

# define ESC_KEY	53
# define W_KEY		13	
# define Z_KEY		6
# define A_KEY		0
# define Q_KEY		12
# define D_KEY		2
# define S_KEY		1
# define E_KEY		14
# define LA_KEY		123
# define RA_KEY		124
# define UA_KEY		126
# define DA_KEY		125

typedef	struct	s_icon
{
	char	*player_icon;
	char	*walls_icon;
	char	*exit_icon;
	char	*ground_icon;
	char	*collectables_icon;
} t_icon;

typedef	struct	s_plr
{
	int	steps;
	int	h;
	int	w;
	int	opened_chests;
} t_plr;

typedef	struct	s_game
{
	void	*mlx_dspl;
	void	*mlx_win;
	t_icon	icons;
	int	height;
	char	**map;
	int	chest_amount;
	t_plr	player;
} t_game;

int	ft_strlen(char *str);
int	flood(char **map, int height, int bo);
int	chest_count(char **map, int height);
void	map_liberator(char **map, int height);
int	fline_count(char *name);
int	is_there_a_map_issue(char *name, char ***map, int height);
char	*ft_gnl(int fd);
char	**arrstr_cpy(char **map, int height);
char	*ft_strjoin(char *start, char *end);
void	game_initializer(t_game *game, char **map, int height);
int	mlx_starter(t_game *game);
int	mlx_closing(t_game *game);
void	mlx_handler(t_game *game);
int	key_redirector(int keynum, t_game *game);
#endif
