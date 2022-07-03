/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:22:59 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/24 15:45:44 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_img(char	*path, t_game *game)
{
	int		x;
	int		y;
	char	*score;

	score = ft_itoa(game->moves_count);
	mlx_string_put(game->mlx_pointer, game->window, 10, 32, 0xf8c820, "moves:");
	mlx_string_put(game->mlx_pointer, game->window, 50, 32, 0xf8c820, score);
	game->img = mlx_xpm_file_to_image(game->mlx_pointer, path, &x, &y);
	mlx_put_image_to_window(game->mlx_pointer, game->window,
		game->img, game->window_draw.x, game->window_draw.y);
	mlx_destroy_image(game->mlx_pointer, game->img);
	free(score);
}

void	draw(char map_input, t_game *game, int i, int j)
{
	if (map_input == 'P')
	{
		game->pos_player.x = j;
		game->pos_player.y = i;
		player_dir(game);
	}
	else if (map_input == '0')
		print_img("./resources/sprites/empty.xpm", game);
	else if (map_input == '1')
		print_img("./resources/sprites/wall.xpm", game);
	else if (map_input == 'C')
	{
		print_img("./resources/sprites/control.xpm", game);
		game->collect += 1;
	}
	else if (map_input == 'E')
		print_img("./resources/sprites/exit_c.xpm", game);
	else if (map_input == 'e')
		print_img("./resources/sprites/exit_o.xpm", game);
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

int	main(int argc, char **argv)
{
	t_dimensions	win_size;
	t_game			game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease Type 2 arguments\n", 2);
		return (ERROR);
	}
	game.map = prepare_map(argv[1], &game);
	if (game.linecheck == 1)
		error_msg_map ("Empy line", &game);
	map_validation(game.map, &win_size);
	game.mlx_pointer = mlx_init();
	game.window = mlx_new_window(game.mlx_pointer, win_size.x * 64,
			win_size.y * 64, "Solong");
	start_struct(&game);
	mlx_hook(game.window, 17, 0, ft_close, &game);
	map_print(game.map, &game);
	mlx_key_hook(game.window, player_moves, &game);
	mlx_loop_hook(game.mlx_pointer, anim, &game);
	mlx_loop(game.mlx_pointer);
}
