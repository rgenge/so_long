/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:24:21 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/18 03:18:21 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//#include "../libft/libft.h"
#define ERROR 1

int free_map_error(char *message, char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
	{
		free(map[row]);
		row++;
	}
	free(map);
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	exit(ERROR);
}

int exit_game(char *message, t_game *game)
{
	int	row;

	row = 0;
	while (game->map[row] != NULL)
	{
		free(game->map[row]);
		row++;
	}
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	mlx_clear_window(game->mlx_pointer, game->window);
	mlx_loop_end(game->mlx_pointer);
	mlx_destroy_window(game->mlx_pointer, game->window);
	mlx_destroy_display(game->mlx_pointer);
	free(game->map);
	free(game->mlx_pointer);
	exit(0);
	return (0);
}
int	error_msg(char *message)
{
	ft_putstr_fd (message, 2);
	ft_putstr_fd ("\n", 2);
	exit(ERROR);
}

int	ft_close(int key)
{
	(void)key;
	ft_putstr_fd ("Exit program\n", 2);
	exit(0);
}

char	**prepare_map(char	*map_path)
{
	int		fd;
	char	*line;
	char	*map_single_line;
	char	**map;

	fd = open (map_path, O_RDONLY);
	map_single_line = get_next_line(fd);
	line = get_next_line (fd);
	while (line != NULL)
	{
		map_single_line = ft_strjoin(map_single_line, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_single_line, '\n');
	free(line);
	free(map_single_line);
	return (map);
}

void	count_checker_print(char **map, int play_count, int coin_count, int exit_count)

{
	if (play_count != 1)
		free_map_error("Map must have one Player", map);
	if (coin_count == 0)
		free_map_error("Map must have one Player", map);
	if (exit_count == 0)
		free_map_error("At least one exit is needed", map);
}

void	count_checker(char **map, int count_lines, int count_col)
{
	int	i;
	int	j;
	int	count[3];

	i = 0;
	j = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (i < count_lines)
	{
		j = 0;
		while (j < count_col)
		{
			if (map[i][j] == 'P')
				count[0]++;
			if (map[i][j] == 'C')
				count[1]++;
			if (map[i][j] == 'E')
				count[2]++;
			j++;
		}
		i++;
	}
	count_checker_print(map, count[0], count[1], count[2]);
}

void	wall_checker(char **map, int count_lines, int count_col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count_lines)
	{
		j = 0;
		if (map[i][0] != '1' || map[i][count_col -1] != '1' )
			free_map_error("Map must be retangular/surrounded by walls", map);
		if (map[i][count_col] != '\0')
			free_map_error("Map must be retangular", map);
		while (j < count_col)
		{
			if (map[0][j] != '1' || map[count_lines - 1][j] != '1')
				free_map_error("Map be retangular/surrounded by walls", map);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' &&
			map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'A') //bonusssssssssssssssss
				{
				free_map_error("Invalid Character", map);
				}
			j++;
		}
		i++;
	}
}

void	map_validation(char **map_char, t_dimensions *win_size)
{
	int	count_col;
	int	count_lines;

	count_col = 0;
	count_lines = 0;
	while (map_char[0][count_col] != '\0')
		count_col++;
	while (map_char[count_lines] != NULL)
		count_lines++;
	win_size->y = count_lines;
	win_size->x = count_col;
	wall_checker(map_char, count_lines, count_col);
	count_checker(map_char, count_lines, count_col);
}

void	print_img(char	*path, t_game *game)
{
	int		x;
	int		y;
	char*		score;//BONUS
	score = ft_itoa(game->moves_count);//BONUS
	mlx_string_put(game->mlx_pointer, game->window, 10, 32, 0xf8c820, "moves:");//BONUS
	mlx_string_put(game->mlx_pointer, game->window, 50, 32, 0xf8c820, score);//BONUS
	game->img = mlx_xpm_file_to_image(game->mlx_pointer, path, &x, &y);
	mlx_put_image_to_window(game->mlx_pointer, game->window,
		game->img, game->window_draw.x, game->window_draw.y);
	mlx_destroy_image(game->mlx_pointer, game->img);
	free(score);//BONUS
}

void	player_dir(t_game *game)
{
	if (game->dir == 'l')
		print_img("../resources/sprites/left.xpm", game);
	else if (game->dir == 'r')
		print_img("../resources/sprites/right.xpm", game);
	else if (game->dir == 'u')
		print_img("../resources/sprites/up.xpm", game);
	else if (game->dir == 'd')
		print_img("../resources/sprites/down.xpm", game);
}
//bonus

int	anim(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->delay++;
	if (game->delay == 80 || game->delay == 40 || game->delay == 1)
	{
		while (game->map[i])
		{
			j = 0;
			game->window_draw.x = 0;
			while (game->map[i][j])
				{
					if(game->delay == 1 && game->map[i][j] == 'A')
					{
						print_img("../resources/sprites/alien2.xpm", game);
						ft_putstr_fd("alien1 ", 2);//teste
					}
					if (game->delay == 40 && game->map[i][j] == 'A')
					{
						print_img("../resources/sprites/alien1.xpm", game);
						ft_putstr_fd("alien2 ", 2);//teste
					}
/*					if (game->delay == 40 && game->map[i][j] == 'A' && game->pos == 0 && game->map[i][j - 1] == '0')
					{
						game->count++;
						if (game->count == 100)
						{
							game->map[i][j] = '0';
							game->map[i][j - 1] = 'A';
							game->pos = 1;
							game->count = 0;
						}

					}
					if (game->delay == 40 && game->map[i][j] == 'A' && game->pos == 1 && game->map[i][j + 1] == '0')
					{
						game->count2 = 0;
						game->count2++;
						if (game->count2 ==100)
						{
						game->map[i][j] = '0';
						game->map[i][j + 1] = 'A';
						game->pos = 0;
						game->count2 = 0;
						}
					}*/
					j++;
				game->window_draw.x += 64;
				}
			game->window_draw.y += 64;
			i++;
		}
		if(game->delay == 80)
			game->delay = 0;
	}
	return(0);
}
//fim bonus

void	draw(char map_input, t_game *game, int i, int j)
{
	if (map_input == 'P')
	{
		game->pos_player.x = j;
		game->pos_player.y = i;
		player_dir(game);
	}
	else if (map_input == '0')
		print_img("../resources/sprites/empty.xpm", game);
	else if (map_input == '1')
		print_img("../resources/sprites/wall.xpm", game);
	else if (map_input == 'C')
	{
		print_img("../resources/sprites/control.xpm", game);
		game->collect += 1;
	}
	else if (map_input == 'E')
		print_img("../resources/sprites/exit_c.xpm", game);
	//bonus
//	else if (map_input == 'A')
//		print_img("../resources/sprites/alien1.xpm", game);
	//fim bonus
	else if (map_input == 'e')
		print_img("../resources/sprites/exit_o.xpm", game);
}

void	map_print(char **map_char, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->window_draw.y = 0;
	game->collect = 0;
	while (map_char[i])
	{
		j = 0;
		game->window_draw.x = 0;
		while (map_char[i][j])
		{
			draw(map_char[i][j], game, i, j);
			j++;
			game->window_draw.x += 64;
		}
		game->window_draw.y += 64;
		i++;
	}
}

void	finish(t_game *game)
{
	if (game->map[game->pos_player.y][game->pos_player.x] == 'e')
	{
		exit_game("You won!\n", game);
	}
	if (game->map[game->pos_player.y][game->pos_player.x] == 'A')
//bonus
	{
		exit_game("You died!\n",game);
	}// final bonus
}

void	redraw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->map[i][j] = '0';
			if (i == game->pos_player.y && j == game->pos_player.x)
				game->map[i][j] = 'P';
			if (game->collect == 0 && game->map[i][j] == 'E')
				game->map[i][j] = 'e';
			j++;
			finish(game);
		}
		i++;
	}
}

void	directions(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
	{
		game->pos_player.y -= 1;
		game->dir = 'u';
	}
	if (keycode == 115 || keycode == 65364)
	{
		game->pos_player.y += 1;
		game->dir = 'd';
	}
	if (keycode == 97 || keycode == 65361)
	{
		game->pos_player.x -= 1;
		game->dir = 'l';
	}
	if (keycode == 100 || keycode == 65363)
	{
		game->pos_player.x += 1;
		game->dir = 'r';
	}
}

int	player_moves(int keycode, t_game *game)
{
	if (keycode == 113 || keycode == 65307)
	{
		error_msg("Exit program");
		return (0);
	}
	directions(keycode, game);
	if (game->map[game->pos_player.y][game->pos_player.x] != '1' &&
		game->map[game->pos_player.y][game->pos_player.x] != 'E')
	{
		game->moves_count++;
		ft_putstr_fd("move: ", 2);
		ft_putnbr_fd(game->moves_count, 2);
		ft_putstr_fd("\n", 2);
		redraw(game);
	}
	map_print(game->map, game);
	return (0);
}

int main(int argc, char **argv)
{
	t_dimensions	win_size;
	t_game			game;

	if (argc != 2)
	{
		ft_putstr_fd("Error Please Type 2 arguments\n", 2);
		return (ERROR);
	}
	game.map = prepare_map(argv[1]);
	map_validation(game.map, &win_size);
	game.mlx_pointer = mlx_init();
	game.window = mlx_new_window(game.mlx_pointer,win_size.x * 64,
			win_size.y * 64, "Solong");
	game.dir = 'r';
	game.delay = 0;
	game.pos = 0;
	game.moves_count = 0;
	mlx_hook(game.window, 17, 0, ft_close, 0);
	map_print(game.map, &game);
	mlx_key_hook(game.window, player_moves, &game);
	mlx_loop_hook(game.mlx_pointer, anim, &game);
	mlx_loop(game.mlx_pointer);
}
