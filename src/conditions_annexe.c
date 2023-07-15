/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions_annexe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:05:55 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/22 19:05:57 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	condition_1(t_games *game, char **map, int x, int y)
{
	if (map[y + 1][x] != 'E')
	{
		map[y + 1][x] = 'P';
		game->modification++;
	}
	else if (map[y + 1][x] == 'E' && ft_search_c(map, 'C') == 0)
	{
		map[y + 1][x] = 'P';
		game->modification++;
	}
}

void	condition_2(t_games *game, char **map, int x, int y)
{
	if (map[y - 1][x] != 'E')
	{
		map[y - 1][x] = 'P';
		game->modification++;
	}
	else if (map[y - 1][x] != 'E' && ft_search_c(map, 'C') == 0)
	{
		map[y - 1][x] = 'P';
		game->modification++;
	}
}

void	condition_3(t_games *game, char **map, int x, int y)
{
	if (map[y][x - 1] != 'E')
	{
		map[y][x - 1] = 'P';
		game->modification++;
	}
	else if (map[y][x - 1] == 'E' && ft_search_c(map, 'C') == 0)
	{
		map[y][x - 1] = 'P';
		game->modification++;
	}
}

void	condition_4(t_games *game, char **map, int x, int y)
{
	if (map[y][x + 1] != 'E')
	{
		map[y][x + 1] = 'P';
		game->modification++;
	}
	else if (map[y][x + 1] == 'E' && ft_search_c(map, 'C') == 0)
	{
		map[y][x + 1] = 'P';
		game->modification++;
	}
}
