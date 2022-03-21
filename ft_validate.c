/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:45:57 by amessah           #+#    #+#             */
/*   Updated: 2022/03/21 21:05:09 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_messag(char *str, char *str2)
{
	write(1, str, ft_strlen(str));
	return (*str2);
}

char	**validate(int fd)
{
	char	**line;

	line = map_read(fd);
	if (!line)
		ft_messag("check line", NULL);
	if (!lenght_comp(line))
		ft_messag("check len or map empty", NULL);
	if (!check_top_bottom_wall(line))
		ft_messag("check top bottom", NULL);
	if (!check_left_right_wall(line))
		ft_messag("check left right", NULL);
	if (!check_charcter(line))
		ft_messag("check char", NULL);
	if (!check_player(line))
		ft_messag("check player", NULL);
	if (!check_exite_collect(line))
		ft_messag("check clec", NULL);
	return (line);
}
