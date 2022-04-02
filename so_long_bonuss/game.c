/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:29:23 by amessah           #+#    #+#             */
/*   Updated: 2022/03/30 20:24:19 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		else if (map->str[i][j] == 'M')
			mlx_put_image_to_window(map->mlx, map->win, map->enemy,
				j * map->img_w, i * map->img_h);
		mlx_print(map);
	}
	else
		image_not_exist();
}

void	map_to_windows(t_long *map, int i, int j)
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
}

void	so_long_game(t_long *map)
{
	xpm_image(map);
	map_to_windows(map, 0, 0);
	mlx_hook(map->win, 2, 1L << 0, mouvement, map);
	mlx_loop_hook(map->mlx, enemy_mouvement, map);
	mlx_hook(map->win, EVENT_CLOSE, 0L, close_win, map);
	mlx_loop(map->mlx);
}
