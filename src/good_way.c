/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:59:02 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/18 16:59:05 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	condition(t_games *game, char **map, int y, int x)
{
	if (map[y][x] == 'P')
	{
		if (map[y][x + 1] != '1' && map[y][x +1] != 'P')
			condition_4(game, map, x, y);
		if (map[y][x -1] != '1' && map[y][x -1] != 'P')
			condition_3(game, map, x, y);
		if (map[y +1][x] != '1' && map[y + 1][x] != 'P')
			condition_1(game, map, x, y);
		if (map[y - 1][x] != '1' && map[y -1][x] != 'P')
			condition_2(game, map, x, y);
	}
}

static void	leave(t_games *game, char **map)
{
	if (game->modification == 0)
	{
		game->cpy_map = copy_map(game, map);
		free_string(map);
		return ;
	}
	else
	{
		game->cpy_map = copy_map(game, map);
		free_string(map);
		game->modification = 0;
		good_way(game);
	}
}

void	good_way(t_games *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = copy_map(game, game->cpy_map);
	free_string(game->cpy_map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			condition(game, map, i, j);
			j++;
		}
		i++;
	}
	leave(game, map);
}

void	verif_way(t_games *game)
{
	int		i;
	int		j;

	i = 0;
	game->cpy_map = copy_map(game, game->map);
	good_way(game);
	while (game->cpy_map[i])
	{
		j = 0;
		while (game->cpy_map[i][j])
		{
			if (game->cpy_map[i][j] == 'E')
				ft_error("NO WAY");
			j++;
		}
		i++;
	}
}
