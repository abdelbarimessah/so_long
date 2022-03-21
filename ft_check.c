/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:20:01 by amessah           #+#    #+#             */
/*   Updated: 2022/03/21 21:11:31 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom_wall(char **str)
{
	int		i;
	char	*top_wall;
	char	*bottom_wall;

	i = 0;
	top_wall = str[0];
	bottom_wall = str[map_lenth(str) - 1];
	while (top_wall[i])
	{
		if (top_wall[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (bottom_wall[i])
	{
		if (bottom_wall[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_left_right_wall(char **str)
{
	int		i;
	int		k;
	int		len;
	int		j;
	char	*line;

	i = 1;
	k = 0;
	len = ft_strlen(*str) - 1;
	j = (int)map_lenth(str);
	while (i < j)
	{
		line = str[i];
		if (line[k] != '1' || line[len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_charcter(char **str)
{
	int		i;
	int		k;
	char	*line;

	i = 1;
	k = 1;
	while (i < (int)map_lenth(str))
	{
		line = str[i];
		k = 1;
		while (k < (int)strlen(line))
		{
			if (line[k] != 'P' && line[k] != 'C' && line[k]
				!= '0' && line[k] != '1' && line[k] != 'E')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	check_player(char **str)
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
			if (line[j] == 'P')
				cont++;
			j++;
		}
		i++;
	}
	if (cont != 1)
		return (0);
	return (1);
}

int	check_exite_collect(char **str)
{
	int		i;
	int		j;
	int		cont1;
	int		cont2;
	char	*line;

	i = 1;
	j = 0;
	cont1 = 0;
	cont2 = 0;
	while (++i < (int)map_lenth(str))
	{
		j = 1;
		line = str[i];
		while (++j < (int)ft_strlen(line))
		{
			if (line[j] == 'C')
				cont1++;
			else if (line[j] == 'E')
				cont2++;
		}
	}
	if (cont1 < 1 || cont2 < 1)
		return (0);
	return (1);
}
