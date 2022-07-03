/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:24:21 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/22 15:09:23 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[len_ext--] == str[len_str--])
			i++;
		else
		{
			ft_putstr_fd ("Error\nMap must have .ber map\n", 2);
			exit(0);
		}
	}
	return (1);
}

int	map_reprint(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->window_draw.y = 0;
	while (game->map[i])
	{
		j = 0;
		game->window_draw.x = 0;
		while (game->map[i][j])
		{
			draw(game->map[i][j], game, i, j);
			j++;
			game->window_draw.x += 64;
		}
		game->window_draw.y += 64;
		i++;
	}
	return (0);
}
