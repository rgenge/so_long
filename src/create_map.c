/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosta-a <chaves_87@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:24:21 by acosta-a          #+#    #+#             */
/*   Updated: 2022/06/25 13:11:43 by acosta-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**prepare_map(char	*map_path, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_single_line;
	char	**map;

	game->linecheck = 0;
	check_extension(map_path, ".ber");
	fd = open (map_path, O_RDONLY);
	map_single_line = get_next_line(fd);
	line = get_next_line (fd);
	if (line == NULL)
		error_msg ("Error\nInvalid Map");
	while (line != NULL)
	{
		if (ft_strncmp(line, "\n\0", 2) == 0)
			game->linecheck = 1;
		map_single_line = ft_strjoin(map_single_line, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(map_single_line, '\n');
	free(line);
	free(map_single_line);
	return (map);
}

void	count_checker_print(char **map, int play_count, int coin_count, int
exit_count)

{
	if (play_count != 1)
		free_map_error("Error\nMap must have one Player", map);
	if (coin_count == 0)
		free_map_error("Error\nMap must have one Coin", map);
	if (exit_count == 0)
		free_map_error("Error\nAt least one exit is needed", map);
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
		if (map[i][0] != '1' || map[i][count_col -1] != '1')
			free_map_error("Error\nMap no retangular/surround by wall", map);
		if (map[i][count_col] != '\0')
			free_map_error("Error\nMap must be retangular", map);
		while (j < count_col)
		{
			if (map[0][j] != '1' || map[count_lines - 1][j] != '1')
				free_map_error("Error\nMap no retangular/surround by wall", map);
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' &&
				map[i][j] != 'E' && map[i][j] != 'C')
			{
				free_map_error("Error\nInvalid Map", map);
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
