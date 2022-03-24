/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:00:56 by amessah           #+#    #+#             */
/*   Updated: 2022/03/23 20:12:50 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	map_lenth(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	lenght_comp(char **str)
{
	char	**line;
	size_t	i;
	size_t	num;

	if (!str[0])
		return (0);
	i = 0;
	line = str;
	num = map_lenth(line);
	while (i < num - 1 && line[i])
	{
		if (ft_strlen(line[i]) != ft_strlen(line[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	close_win(int key, void *param)
{
	(void)key;
	(void)param;
	write(1, "\ngame over !\n", 14);
	exit(0);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
