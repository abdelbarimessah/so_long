/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:45:57 by amessah           #+#    #+#             */
/*   Updated: 2022/03/23 22:11:15 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_messag(char *str1, char **st2, char **line)
{
	write(2, str1, ft_strlen(str1));
	ft_free(line);
	return (st2);
}

char	**validate(int fd)
{
	char	**line;

	line = map_read(fd);
	if (!line)
		ft_messag("check line", NULL, line);
	if (!lenght_comp(line))
		ft_messag("check len or map empty", NULL, line);
	if (!check_top_bottom_wall(line))
		ft_messag("check top bottom", NULL, line);
	if (!check_left_right_wall(line))
		ft_messag("check left right", NULL, line);
	if (!check_charcter(line))
		ft_messag("check char", NULL, line);
	if (!check_player(line))
		ft_messag("check player", NULL, line);
	if (!check_exite_collect(line))
		ft_messag("check clec", NULL, line);
	if (!check_enemy(line))
		ft_messag("check enemy", NULL, line);
	return (line);
}
