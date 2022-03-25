/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:45:57 by amessah           #+#    #+#             */
/*   Updated: 2022/03/26 00:47:48 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_messag(char *str1, char **line)
{
	write(2, str1, ft_strlen(str1));
	ft_free(line);
	exit(1);
}

char	**validate(int fd)
{
	char	**line;

	line = map_read(fd);
	if (!line)
		ft_messag("check line", line);
	if (!lenght_comp(line))
		ft_messag("check len or map empty", line);
	if (!check_top_bottom_wall(line))
		ft_messag("check top bottom", line);
	if (!check_left_right_wall(line))
		ft_messag("check left right", line);
	if (!check_charcter(line))
		ft_messag("check char", line);
	if (!check_player(line))
		ft_messag("check player", line);
	if (!check_exite_collect(line))
		ft_messag("check clec and exit", line);
	if (!check_enemy(line))
		ft_messag("check enemy", line);
	return (line);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
