/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:46:39 by amessah           #+#    #+#             */
/*   Updated: 2022/03/21 21:17:27 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	i = strlen(str);
	if (str == 0 || i < 5)
		return (0);
	if (strcmp(str + (i - 4), ".ber") == 0)
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

void	read_xpm(int i, int j)
{
	int		fd;
	char	**tab;

	tab = malloc(7 * sizeof(char *));
	tab[0] = ft_strdup(C_DOOR);
	tab[1] = ft_strdup(O_DOOR);
	tab[2] = ft_strdup(WALL);
	tab[3] = ft_strdup(PLAYER);
	tab[4] = ft_strdup(EMPTY);
	tab[5] = ft_strdup(MONEY);
	tab[6] = NULL;
	while (++j < 6)
	{
		fd = open(tab[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "ko", 2);
			close(fd);
			ft_free(tab);
			exit(0);
		}
		close(fd);
	}
	ft_free(tab);
}

void	xpm_image(t_long *map)
{
	map->mlx = mlx_init();
	map->o_door = mlx_xpm_file_to_image(map->mlx, O_DOOR,
			&map->img_w, &map->img_h);
	map->c_door = mlx_xpm_file_to_image(map->mlx, C_DOOR,
			&map->img_w, &map->img_h);
	map->money = mlx_xpm_file_to_image(map->mlx, MONEY,
			&map->img_w, &map->img_h);
	map->player = mlx_xpm_file_to_image(map->mlx, PLAYER,
			&map->img_w, &map->img_h);
	map->wall = mlx_xpm_file_to_image(map->mlx, WALL,
			&map->img_w, &map->img_h);
	map->black = mlx_xpm_file_to_image(map->mlx, EMPTY,
			&map->img_w, &map->img_h);
	map->cont = 0;
	map->win = mlx_new_window(map->mlx, (map->map_len) * 60,
			(map->map_tall) * 60, "so_long");
}
