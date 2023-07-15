/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_monstres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:35 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/22 18:20:39 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	droite_mst(t_games *game, int i)
{
	incruster_img(game, game->sol, game->mon[i].pos.y, game->mon[i].pos.x);
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = '0';
	game->mon[i].pos.y += 1;
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = 'M';
	incruster_img(game, game->pmo, game->mon[i].pos.y, game->mon[i].pos.x);
}

void	gauche_mst(t_games *game, int i)
{
	incruster_img(game, game->sol, game->mon[i].pos.y, game->mon[i].pos.x);
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = '0';
	game->mon[i].pos.y -= 1;
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = 'M';
	incruster_img(game, game->pmo, game->mon[i].pos.y, game->mon[i].pos.x);
}

void	down_mst(t_games *game, int i)
{
	incruster_img(game, game->sol, game->mon[i].pos.y, game->mon[i].pos.x);
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = '0';
	game->mon[i].pos.x += 1;
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = 'M';
	incruster_img(game, game->pmo, game->mon[i].pos.y, game->mon[i].pos.x);
}

void	up_mst(t_games *game, int i)
{
	incruster_img(game, game->sol, game->mon[i].pos.y, game->mon[i].pos.x);
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = '0';
	game->mon[i].pos.x -= 1;
	game->map[game->mon[i].pos.x][game->mon[i].pos.y] = 'M';
	incruster_img(game, game->pmo, game->mon[i].pos.y, game->mon[i].pos.x);
}
