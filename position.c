/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:39:09 by amessah           #+#    #+#             */
/*   Updated: 2022/03/21 20:57:28 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	position_i(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				break ;
			j++;
		}
		if (str[i][j] == 'P')
			break ;
		i++;
	}
	return (i);
}

int	position_j(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				break ;
			j++;
		}
		if (str[i][j] == 'P')
			break ;
		i++;
	}
	return (j);
}
