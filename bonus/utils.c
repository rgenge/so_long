/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:24:21 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/24 14:36:16 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

void	start_struct(t_game *game)
{
	game->dir = 'r';
	game->delay = 0;
	game->pos = 0;
	game->pos2 = 0;
	game->moves_count = 0;
	game->count = 0;
	game->count2 = 0;
}
