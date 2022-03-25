/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:23 by amessah           #+#    #+#             */
/*   Updated: 2022/03/25 15:32:15 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_cloctible(char **str)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				cont++;
			j++;
		}
		i++;
	}
	return (cont);
}

void	draw(t_long *map, int i, int j)
{
	if (map->wall && map->player && map->o_door
		&& map->c_door && map->money && map->black)
	{
		if (map->str[i][j] == '1')
			mlx_put_image_to_window(map->mlx, map->win, map->wall,
				j * map->img_w, i * map->img_h);
		else if (map->str[i][j] == 'E')
			open_close_door(map, i, j);
		else if (map->str[i][j] == 'P')
			mlx_put_image_to_window(map->mlx, map->win, map->player,
				j * map->img_w, i * map->img_h);
		else if (map->str[i][j] == 'C')
			mlx_put_image_to_window(map->mlx, map->win, map->money,
				j * map->img_w, i * map->img_h);
		else if (map->str[i][j] == '0')
			mlx_put_image_to_window(map->mlx, map->win, map->black,
				j * map->img_w, i * map->img_h);
	}
	else
		image_not_exist();
}

void	map_to_windows(t_long *map, int i, int j, char *cont)
{
	i = -1;
	while (map->str[++i])
	{
		j = -1;
		while (map->str[i][++j])
		{
			draw(map, i, j);
		}
	}
	cont = ft_itoa(map->cont);
	write(1, "\ncounter : ", 12);
	write(1, cont, ft_strlen(cont));
	free(cont);
}

void	so_long_game(t_long *map)
{
	read_xpm(0, -1);
	xpm_image(map);
	map_to_windows(map, 0, 0, NULL);
	mlx_hook(map->win, 2, 1L, mouvement, map);
	mlx_hook(map->win, EVENT_CLOSE, 0L, close_win, map);
	mlx_loop(map->mlx);
	map = NULL;
}
