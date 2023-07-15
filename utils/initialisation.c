/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:27:44 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/19 21:47:30 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	moove_player_dir(t_games *game)
{
	if (game->player.dir == UP)
		incruster_img(game, game->player.playerw, game->pos.x, game->pos.y);
	else if (game->player.dir == DOWN)
		incruster_img(game, game->player.players, game->pos.x, game->pos.y);
	else if (game->player.dir == RIGHT)
		incruster_img(game, game->player.playerd, game->pos.x, game->pos.y);
	else if (game->player.dir == LEFT)
		incruster_img(game, game->player.playera, game->pos.x, game->pos.y);
}

void	structure_init_x(t_games *game)
{
	int	j;

	j = 0;
	while (game->map[0][j])
	{
		j++;
	}
	game->axes.x = j - 1;
}

void	structure_init_y(t_games *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		i++;
	}
	game->axes.y = i;
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_search_c(char **map, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}
