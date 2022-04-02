/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:46:39 by amessah           #+#    #+#             */
/*   Updated: 2022/03/30 20:00:32 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	file_check(char *str)
{
	int		i;
	char	*str1;
	int		cont;

	i = 0;
	cont = 0;
	str1 = str;
	while (str1[i])
	{
		if (str1[i] == '.')
			cont++;
		i++;
	}
	if (cont != 1)
		return (0);
	i = ft_strlen(str);
	if (str == 0 || i < 5)
		return (0);
	if (ft_strcmp(str + (i - 4), ".ber") == 0)
		return (1);
	return (0);
}

char	*reader(int fd)
{
	char	*buff;
	char	*map;
	int		i;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	map = malloc(1);
	if (!buff || !map)
		return (NULL);
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		map = ft_strjoin(map, buff);
	}
	free(buff);
	return (map);
}

char	**map_read(int fd)
{
	char	*map;
	char	**map_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = reader(fd);
	if (!map)
		return (0);
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n')
			|| ((map[i] == '\n' && map[i + 1] == '\0'))
			|| ((map[i] == '\n' && map[i - 1] == '\0')))
			return (NULL);
		i++;
	}
	map_line = ft_split(map, '\n');
	free(map);
	return (map_line);
}

void	xpm_image(t_long *map)
{
	map->mlx = mlx_init();
	map->o_door = mlx_xpm_file_to_image(map->mlx, O_DOOR,
			&map->img_w, &map->img_h);
	map->c_door = mlx_xpm_file_to_image(map->mlx, C_DOOR,
			&map->img_w, &map->img_h);
	map->money = mlx_xpm_file_to_image(map->mlx, MONEY1,
			&map->img_w, &map->img_h);
	map->player = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_w, &map->img_h);
	map->wall = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_w, &map->img_h);
	map->black = mlx_xpm_file_to_image(map->mlx, EMPTY,
			&map->img_w, &map->img_h);
	map->enemy = mlx_xpm_file_to_image(map->mlx, ENEMY,
			&map->img_w, &map->img_h);
	map->cont = 0;
	map->win = mlx_new_window(map->mlx, (map->map_len) * 64,
			(map->map_tall) * 64, "so_long_with_bonus");
}
