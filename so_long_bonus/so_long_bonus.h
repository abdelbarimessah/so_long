/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:45:37 by amessah           #+#    #+#             */
/*   Updated: 2022/03/26 00:43:13 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 1
# define EVENT_CLOSE 17
# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define KEY_ESC 53

# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include<string.h>
# include<unistd.h>
# include<mlx.h>

# define O_DOOR "./image/door_o.xpm"
# define C_DOOR "./image/door_c.xpm"
# define WALL "./image/wall3.xpm"
# define EMPTY "./image/black-square.xpm"
# define PLAYER "./image/cricket-ball2.xpm"
# define ENEMY "./image/ghost.xpm"
# define MONEY1 "./image/rsz_layer_1.xpm"
# define MONEY2 "./image/rsz_layer_2.xpm"
# define MONEY3 "./image/rsz_layer_3.xpm"
# define MONEY4 "./image/rsz_layer_4.xpm"

typedef struct so_long
{
	char	**str;
	int		map_len;
	int		map_tall;
	int		cont;
	int		img_h;
	int		img_w;
	void	*mlx;
	void	*o_door;
	void	*c_door;
	void	*money;
	void	*player;
	void	*black;
	void	*wall;
	void	*enemy;
	void	*win;
}t_long;

size_t	ft_strlen(const char *str);
size_t	map_lenth(char **str);
int		ft_strcmp(const char *s1, const char *s2);
int		file_check(char *str);
int		file_check(char *str);
int		lenght_comp(char **str);
int		check_top_bottom_wall(char **str);
int		check_left_right_wall(char **str);
int		check_charcter(char **str);
int		check_player(char **str);
int		check_exite_collect(char **str);
int		check_cloctible(char **str);
int		check_enemy(char **str);
int		close_win(int key, void *param);
int		mouvement(int key, void *param);
int		w_mouve(t_long *map, int i, int j);
int		s_mouve(t_long *map, int i, int j);
int		a_mouve(t_long *map, int i, int j);
int		d_mouve(t_long *map, int i, int j);
int		space_mouve(t_long *map, int i, int j);
int		position_j(char **str);
int		position_i(char **str);
int		enemy_position_j(char **str);
int		enemy_position_i(char **str);
int		up_mouve(t_long *map, int i, int j);
int		down_mouve(t_long *map, int i, int j);
int		left_mouve(t_long *map, int i, int j);
int		right_mouve(t_long *map, int i, int j);
int		enemy_mouvement(t_long *map);

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*reader(int fd);
char	**map_read(int fd);
char	**validate(int fd);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	**ft_messag(char *str, char **line);

void	open_close_door(t_long *map, int i, int j);
void	image_not_exist(void);
void	you_win(t_long *map);
void	you_lose(t_long *map);
void	mlx_print(t_long *map);
void	ft_free(char **tab);
void	so_long_game(t_long *map);
void	read_xpm(int i, int j);
void	xpm_image(t_long *map);
void	map_to_windows(t_long *map, int i, int j, int k);
void	draw(t_long *map, int i, int j);
void	coin_animation(t_long *map);
void	rand_mouve(int key, int i, int j, t_long *map);

#endif