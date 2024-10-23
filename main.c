/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:44:39 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/22 22:15:25 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map_name;
	char	**map;
	int	height;

	if (argc != 2)
		return (1);
	map_name = argv[1];
	height = fline_count(map_name);
	if (height < 3)
		return (1);
	if (is_there_a_map_issue(map_name, &map, height))
		return (1);
	printf("all good\n");
	map_liberator(map, height);
}
