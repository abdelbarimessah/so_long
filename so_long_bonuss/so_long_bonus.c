/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:52:23 by amessah           #+#    #+#             */
/*   Updated: 2022/03/30 19:43:45 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_long	map;

	if (argc == 2 && file_check(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			write(1, "error", 5);
		else
		{
			map.str = validate(fd);
			if (map.str)
			{
				map.map_len = ft_strlen(map.str[0]);
				map.map_tall = map_lenth(map.str);
				so_long_game(&map);
				close(fd);
				ft_free(map.str);
			}
			ft_free(map.str);
		}
	}
	else
		write(1, "error", 5);
	return (0);
}
