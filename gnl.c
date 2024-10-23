/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilamber <nilamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:42:52 by nilamber          #+#    #+#             */
/*   Updated: 2024/10/23 14:24:34 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_till_nl(char *str)
{
	int	i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * i);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

int	is_there_a_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (1);
	return (0);
}

void	clear_till_nl(char str[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		str[i++] = '\0';
	while (str[i])
	{
		str[i++] = '\0';
		str[j++] = str[i];	
	}
}

char	*ft_gnl(int fd)
{
	static char	buffer[42];
	char		*line;
	int		rv;

	//printf("(gnl) buffer1 = %s\n", buffer);
	if (!*buffer)
		rv = read(fd, buffer, 42);
	if (rv <= 0)
		return (NULL);
	line = get_till_nl(buffer);
	//printf("\n(gnl) line = %s\n", line);
	//printf("(gnl) buffer = %s\n", buffer);
	if (is_there_a_nl(buffer))
		clear_till_nl(buffer);
	else
	{
		while (!is_there_a_nl(buffer) || rv <= 0)
		{
			rv = read(fd, buffer, 42);
			line = ft_strjoin(line, get_till_nl(buffer));
			clear_till_nl(buffer);
		}
	}
	return (line);
}
