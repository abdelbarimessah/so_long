/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:49:52 by amessah           #+#    #+#             */
/*   Updated: 2022/03/30 19:58:16 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	up_mouve(t_long *map, int i, int j)
{
	if (map->str[i - 1][j] == 'E' || map->str[i - 1][j] == '1'
		|| map->str[i - 1][j] == 'C' || map->str[i - 1][j] == 'M')
		return (0);
	if (map->str[i - 1][j] == 'P')
	{
		write(1, "you lose\n", 10);
		ft_free(map->str);
		exit(0);
	}
	else
	{
		map->str[i][j] = '0';
		map->str[i - 1][j] = 'M';
	}
	return (1);
}

int	down_mouve(t_long *map, int i, int j)
{
	if (map->str[i + 1][j] == 'E' || map->str[i + 1][j] == '1'
		|| map->str[i + 1][j] == 'C' || map->str[i + 1][j] == 'M')
		return (0);
	if (map->str[i + 1][j] == 'P')
	{
		write(1, "you lose\n", 10);
		ft_free(map->str);
		exit(0);
	}
	else
	{
		map->str[i][j] = '0';
		map->str[i + 1][j] = 'M';
	}
	return (1);
}

int	left_mouve(t_long *map, int i, int j)
{
	if (map->str[i][j - 1] == 'E' || map->str[i][j - 1] == '1'
		|| map->str[i][j - 1] == 'C' || map->str[i][j - 1] == 'M')
		return (0);
	if (map->str[i][j - 1] == 'P')
	{
		write(1, "you lose\n", 10);
		ft_free(map->str);
		exit(0);
	}
	else
	{
		map->str[i][j] = '0';
		map->str[i][j - 1] = 'M';
	}
	return (1);
}

int	right_mouve(t_long *map, int i, int j)
{
	if (map->str[i][j + 1] == 'E' || map->str[i][j + 1] == '1'
		|| map->str[i][j + 1] == 'C' || map->str[i][j + 1] == 'M')
		return (0);
	if (map->str[i][j + 1] == 'P')
	{
		write(1, "you lose\n", 10);
		ft_free(map->str);
		exit(0);
	}
	else
	{
		map->str[i][j] = '0';
		map->str[i][j + 1] = 'M';
	}
	return (1);
}

void	open_close_door(t_long *map, int i, int j)
{
	if (check_cloctible(map->str))
		mlx_put_image_to_window(map->mlx, map->win, map->c_door,
			j * map->img_w, i * map->img_h);
	else
		mlx_put_image_to_window(map->mlx, map->win, map->o_door,
			j * map->img_w, i * map->img_h);
}
