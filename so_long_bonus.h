/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:26:43 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/25 13:18:33 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H
#include "libft/libft.h"
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>
#define ERROR 1

typedef struct dimensions
{
	int	x;
	int	y;
}	t_dimensions;

typedef struct s_game
{
	void			*mlx_pointer;
	void			*window;
	t_dimensions	window_draw;
	char			**map;
	void			*img;
	t_dimensions	pos_player;
	char			dir;
	int				collect;
	int				moves_count;
	int				delay;
	int				pos;
	int				pos2;
	int				count;
	int				count2;
	int				linecheck;
}	t_game;

int		free_map_error(char *message, char **map);
int		exit_game(char *message, t_game *game);
int		error_msg(char *message);
int		ft_close(t_game *game);
void	finish(t_game *game);
char	**prepare_map(char	*map_path, t_game *game);
void	count_checker_print(char **map, int play_count, int coin_count,
			int exit_count);
void	count_checker(char **map, int count_lines, int count_col);
void	wall_checker(char **map, int count_lines, int count_col);
void	map_validation(char **map_char, t_dimensions *win_size);
void	print_img(char	*path, t_game *game);
void	player_dir(t_game *game);
void	draw(char map_input, t_game *game, int i, int j);
void	map_print(char **map_char, t_game *game);
void	redraw(t_game *game);
void	directions(int keycode, t_game *game);
int		player_moves(int keycode, t_game *game);
int		check_extension(char *str, char *extension);
void	animmoveprint(t_game *game, int i, int j);
void	animmove(t_game *game, int i, int j);
int		anim(t_game *game);
int		check_extension(char *str, char *extension);
int		error_msg_map(char *message, t_game *game);
void	start_struct(t_game *game);

#endif
