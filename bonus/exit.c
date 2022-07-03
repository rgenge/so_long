/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:42:33 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/24 15:46:06 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	free_map_error(char *message, char **map)
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

int	exit_game(char *message, t_game *game)
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

int	error_msg_map(char *message, t_game *game)
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
	free(game->map);
	exit(0);
	return (0);
}

int	ft_close(t_game *game)
{
	exit_game("Exit program\n", game);
	return (0);
}
