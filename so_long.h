/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 01:08:12 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/23 14:15:51 by nilamber         ###   ########.fr       */
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

int	ft_strlen(char *str);
int	flood(char **map, int height, int bo);
int	chest_count(char **map, int height);
void	map_liberator(char **map, int height);
int	fline_count(char *name);
int	is_there_a_map_issue(char *name, char ***map, int height);
char	*ft_gnl(int fd);
char	**arrstr_cpy(char **map, int height);
char	*ft_strjoin(char *start, char *end);
typedef	struct	s_pos
{
	int	h;
	int	w;
} t_pos;
#endif
