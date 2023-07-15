/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_monsters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:29:02 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/22 18:29:07 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_patrouilles(t_games *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = collectib_compteur(game, 'M');
	free(game->mon);
	game->mon = malloc(sizeof(t_picture) * k + 1);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				game->mon[k - 1].pos.x = i;
				game->mon[k - 1].pos.y = j;
				k--;
			}
			j++;
		}
		i++;
	}
}

static void	ft_condition_deplacement3(t_games *game, int i)
{
	if (game->map[game->mon[i].pos.x + 1][game->mon[i].pos.y] == '0' && \
	game->map[game->mon[i].pos.x + 1][game->mon[i].pos.y] != 'P')
		down_mst(game, i);
	else if (game->map[game->mon[i].pos.x][game->mon[i].pos.y + 1] == '0' && \
	game->map[game->mon[i].pos.x][game->mon[i].pos.y + 1] != 'P')
		droite_mst(game, i);
	else if (game->map[game->mon[i].pos.x - 1][game->mon[i].pos.y] == '0' && \
	game->map[game->mon[i].pos.x - 1][game->mon[i].pos.y] != 'P')
		up_mst(game, i);
	else if (game->map[game->mon[i].pos.x][game->mon[i].pos.y - 1] == '0' && \
	game->map[game->mon[i].pos.x][game->mon[i].pos.y - 1] != 'P')
		gauche_mst(game, i);
}

static void	ft_condition_deplacement2(t_games *game, int i)
{
	if (game->map[game->mon[i].pos.x][game->mon[i].pos.y - 1] == '0' && \
	game->map[game->mon[i].pos.x][game->mon[i].pos.y - 1] != 'P')
		gauche_mst(game, i);
	else if (game->map[game->mon[i].pos.x + 1][game->mon[i].pos.y] == '0' && \
	game->map[game->mon[i].pos.x + 1][game->mon[i].pos.y] != 'P')
		down_mst(game, i);
	else if (game->map[game->mon[i].pos.x][game->mon[i].pos.y + 1] == '0' && \
	game->map[game->mon[i].pos.x][game->mon[i].pos.y + 1] != 'P')
		droite_mst(game, i);
	else if (game->map[game->mon[i].pos.x - 1][game->mon[i].pos.y] == '0' && \
	game->map[game->mon[i].pos.x][game->mon[i].pos.y - 1] != 'P')
		up_mst(game, i);
}

static void	ft_condition_deplacement(t_games *game, int i)
{
	if (i % 2)
		ft_condition_deplacement3(game, i);
	else
		ft_condition_deplacement2(game, i);
}

void	ft_patrouilles2(t_games *game)
{
	int	i;
	int	k;

	i = 0;
	k = collectib_compteur(game, 'M');
	ft_patrouilles(game);
	while (i < k)
	{
		ft_condition_deplacement(game, i);
		i++;
	}
}
