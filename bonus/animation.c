/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 04:22:59 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/24 14:29:19 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animmoveprint(t_game *game, int i, int j)
{
	if (game->delay == 1 && game->map[i][j] == 'A')
		print_img("./resources/sprites/alien2.xpm", game);
	if (game->delay == 1000 && game->map[i][j] == 'A')
		print_img("./resources/sprites/alien1.xpm", game);
	if (game->delay == 2000)
		game->delay = 0;
	draw (game->map[i][j], game, i, j);
}

void	animmove(t_game *game, int i, int j)
{
	animmoveprint(game, i, j);
	if (game->delay == 1 && game->map[i][j] == '0' && game->pos < 10 &&
		game->map[i][j - 1] == 'A')
	{
		game->count++;
		if (game->count == 7)
		{
			game->map[i][j] = 'A';
			game->map[i][j - 1] = '0';
			game->pos++;
			game->count = 0;
		}
	}
	else if (game->delay == 1000 && game->map[i][j] == '0' && game->pos < 30 &&
		game->map[i][j + 1] == 'A')
	{
		game->count2++;
		if (game->count2 == 7)
		{
			game->map[i][j] = 'A';
			game->map[i][j + 1] = '0';
			game->pos--;
			game->count2 = 0;
		}
	}
}

int	anim(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->window_draw.y = 0;
	game->delay++;
	if (game->delay == 2000 || game->delay == 1000 || game->delay == 1)
	{
		while (game->map[i])
		{
			j = 0;
			game->window_draw.x = 0;
			while (game->map[i][j])
			{
				animmove(game, i, j);
				j++;
				game->window_draw.x += 64;
			}
			game->window_draw.y += 64;
			i++;
		}
	}
	return (0);
}
