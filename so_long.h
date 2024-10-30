/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:08:12 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/28 01:46:39 by nilamber         ###   ########.fr       */
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

# define ESC_KEY	65307//53
# define W_KEY		87//13	
# define W_LC_KEY		119
# define Z_KEY		90//6
# define Z_LC_KEY		122
# define A_KEY		65//0
# define A_LC_KEY		97
# define Q_KEY		81//12
# define Q_LC_KEY		113
# define D_KEY		68//2
# define D_LC_KEY		100
# define S_KEY		83//1
# define S_LC_KEY		115
# define E_KEY		14
# define LA_KEY		65361//123
# define RA_KEY		65363//124
# define UA_KEY		65362//126
# define DA_KEY		65364//125

typedef struct s_image
{
	int		offset_x;
	int		range_x;
	int		range_y;
	int		offset_y;
	int		size;
	void	*player;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*collectable;
}	t_image;

typedef struct s_plr
{
	int	steps;
	int	h;
	int	w;
	int	opened_chests;
}	t_plr;

typedef struct s_game
{
	void	*mlx_dspl;
	void	*mlx_win;
	int		s_height;
	int		s_width;
	t_image	images;
	int		m_height;
	int		m_width;
	char	**map;
	int		chest_amount;
	t_plr	player;
}	t_game;

int		ft_strlen(char *str);
int		flood(char **map, int height, int bool);
int		chest_count(char **map, int height);
void	map_liberator(char **map, int height);
int		fline_count(char *name);
int		is_there_a_map_issue(char *name, char ***map, int height);
char	*ft_gnl(int fd);
char	**arrstr_cpy(char **map, int height);
char	*ft_strjoin(char *start, char *end);
void	print_steps(int steps);
void	game_initializer(t_game *game, char **map, int height);
void	image_initializer(t_game *game);
int		mlx_starter(t_game *game);
int		mlx_closing(t_game *game);
void	mlx_handler(t_game *game);
int		key_redirector(int keynum, t_game *game);
void	mlx_refresh_whole_frame(t_game *game);
void	mlx_refresh_player(t_game *game, int last_x, int last_y);
int		wall_in_range(t_game *game);
#endif
