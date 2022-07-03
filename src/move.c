/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:22:59 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/24 15:52:36 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_dir(t_game *game)
{
	if (game->dir == 'l')
		print_img("./resources/sprites/left.xpm", game);
	else if (game->dir == 'r')
		print_img("./resources/sprites/right.xpm", game);
	else if (game->dir == 'u')
		print_img("./resources/sprites/up.xpm", game);
	else if (game->dir == 'd')
		print_img("./resources/sprites/down.xpm", game);
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
		exit_game("Exit program", game);
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

void	finish(t_game *game)
{
	if (game->map[game->pos_player.y][game->pos_player.x] == 'e')
		exit_game("You survived!\n", game);
}
