/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:17:38 by amessah           #+#    #+#             */
/*   Updated: 2022/03/24 16:05:37 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	w_mouve(t_long *map, int i, int j)
{
	i = position_i(map->str);
	j = position_j(map->str);
	if (map->str[i - 1][j] == 'E' && !check_cloctible(map->str))
		you_win(map);
	if (map->str[i - 1][j] == 'E' || map->str[i -1][j] == '1')
		return (0);
	if (map->str[i - 1][j] == 'C')
	{
		map->str[i][j] = '0';
		map->str[i - 1][j] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->black,
			j * map->img_w, (i - 1) * map->img_h);
	}
	if (map->str[i - 1][j] == 'M')
		you_lose(map);
	else
	{
		map->str[i][j] = '0';
		map->str[i - 1][j] = 'P';
	}
	map->cont++;
	map_to_windows(map, 0, 0, 1);
	return (1);
}

int	s_mouve(t_long *map, int i, int j)
{
	i = position_i(map->str);
	j = position_j(map->str);
	if (map->str[i + 1][j] == 'E' && !check_cloctible(map->str))
		you_win(map);
	if (map->str[i + 1][j] == 'E' || map->str[i + 1][j] == '1')
		return (0);
	if (map->str[i + 1][j] == 'C')
	{
		map->str[i][j] = '0';
		map->str[i + 1][j] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->black,
			j * map->img_w, (i + 1) * map->img_h);
	}
	if (map->str[i + 1][j] == 'M')
		you_lose(map);
	else
	{
		map->str[i][j] = '0';
		map->str[i + 1][j] = 'P';
	}
	map->cont++;
	map_to_windows(map, 0, 0, 1);
	return (1);
}

int	a_mouve(t_long *map, int i, int j)
{
	i = position_i(map->str);
	j = position_j(map->str);
	if (map->str[i][j - 1] == 'E' && !check_cloctible(map->str))
		you_win(map);
	if (map->str[i][j - 1] == 'E' || map->str[i][j - 1] == '1')
		return (0);
	if (map->str[i][j - 1] == 'C')
	{
		map->str[i][j] = '0';
		map->str[i][j - 1] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->black,
			(j - 1) * map->img_w, i * map->img_h);
	}
	if (map->str[i][j - 1] == 'M')
		you_lose(map);
	else
	{
		map->str[i][j] = '0';
		map->str[i][j - 1] = 'P';
	}
	map->cont++;
	map_to_windows(map, 0, 0, 1);
	return (1);
}

int	d_mouve(t_long *map, int i, int j)
{
	i = position_i(map->str);
	j = position_j(map->str);
	if (map->str[i][j + 1] == 'E' && !check_cloctible(map->str))
		you_win(map);
	if (map->str[i][j + 1] == 'E' || map->str[i][j + 1] == '1')
		return (0);
	if (map->str[i][j + 1] == 'C')
	{
		map->str[i][j] = '0';
		map->str[i][j + 1] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->black,
			(j + 1) * map->img_w, i * map->img_h);
	}
	if (map->str[i][j + 1] == 'M')
		you_lose(map);
	else
	{
		map->str[i][j] = '0';
		map->str[i][j + 1] = 'P';
	}
	map->cont++;
	map_to_windows(map, 0, 0, 1);
	return (1);
}

int	mouvement(int key, void *param)
{
	t_long	*map;

	map = (t_long *)param;
	if (key == KEY_W)
		w_mouve(map, 0, 0);
	if (key == KEY_S)
		s_mouve(map, 0, 0);
	if (key == KEY_A)
		a_mouve(map, 0, 0);
	if (key == KEY_D)
		d_mouve(map, 0, 0);
	if (key == KEY_ESC)
	{
		write(1, "\ngame over !\n", 14);
		ft_free(map->str);
		exit(0);
	}
	return (1);
}
