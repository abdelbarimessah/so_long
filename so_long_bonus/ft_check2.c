/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:50:57 by amessah           #+#    #+#             */
/*   Updated: 2022/03/24 16:11:30 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_enemy(char **str)
{
	int		i;
	int		j;
	int		cont;
	char	*line;

	i = 1;
	cont = 0;
	while (i < (int)map_lenth(str))
	{
		line = str[i];
		j = 1;
		while (j < (int)ft_strlen(line))
		{
			if (line[j] == 'M')
				cont++;
			j++;
		}
		i++;
	}
	if (cont == 0)
		return (0);
	return (1);
}

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

void	you_lose(t_long *map)
{
	write(1, "\nyou lose\n", 11);
	ft_free(map->str);
	exit(1);
}

void	you_win(t_long *map)
{
	write(1, "\ngood game\n", 11);
	ft_free(map->str);
	exit(0);
}

void	image_not_exist(void)
{
	write(1, "image not existe", 17);
	exit(1);
}
