/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 23:31:49 by amessah           #+#    #+#             */
/*   Updated: 2022/03/29 15:52:22 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	coin_animation(t_long *map)
{
	static int	i;

	if (i <= 10)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY1,
				&map->img_w, &map->img_h);
	else if (i <= 20)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY2,
				&map->img_w, &map->img_h);
	else if (i <= 30)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY3,
				&map->img_w, &map->img_h);
	else if (i <= 40)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY4,
				&map->img_w, &map->img_h);
	else if (i <= 50)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY6,
				&map->img_w, &map->img_h);
	else if (i <= 60)
		map->money = mlx_xpm_file_to_image(map->mlx, MONEY5,
				&map->img_w, &map->img_h);
	i++;
	if (i == 60)
		i = 0;
}

void	mlx_print(t_long *map)
{
	char	*s;

	s = ft_itoa(map->cont);
	mlx_string_put(map->mlx, map->win, 900, 10, 0x00ffffff, "Moves : ");
	mlx_string_put(map->mlx, map->win, 1000, 10, 0x00ffffff, s);
	free(s);
}

void	rand_mouve(int key, int i, int j, t_long *map)
{
	if (key == 1)
		up_mouve(map, i, j);
	else if (key == 2)
		down_mouve(map, i, j);
	else if (key == 3)
		left_mouve(map, i, j);
	else if (key == 4)
		right_mouve(map, i, j);
}

int	enemy_mouvement(t_long *map)
{
	int	j;
	int	i;
	int	key;

	i = -1;
	while (map->str[++i])
	{
		j = -1;
		while (map->str[i][++j])
		{
			if (map->str[i][j] == 'M')
			{
				mlx_put_image_to_window(map->mlx, map->win, map->enemy,
					j * map->img_h, i * map->img_w);
				key = rand() % 20;
				rand_mouve(key, i, j, map);
			}
		}
	}
	coin_animation(map);
	map_to_windows(map, 0, 0);
	return (0);
}
