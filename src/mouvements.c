/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:32:20 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/19 19:54:23 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	right(t_games *game, int y, int x, int c)
{
	ft_patrouilles2(game);
	if (game->map[y][x + 1] == 'M')
	{
		ft_printf("you were hit by a fireball, you lost, try again");
		exit(EXIT_FAILURE);
	}
	if (game->map[y][x + 2] == 'C')
		incruster_img(game, game->objet2, x + 2, y);
	if (game->map[y][x + 1] == 'C')
	{
		c--;
		game->objets.collect = c;
	}
	if (game->map[y][x + 2] == 'E' && game->objets.collect == 0)
		incruster_img(game, game->exit2, x + 2, y);
	if (game->map[y][x + 1] == 'E' && game->objets.collect == 0)
		exit(EXIT_SUCCESS);
	if (game->map[y][x + 1] == 'E' && game->objets.collect != 0)
		return ;
	compteur_pas(game);
	game->map[y][x] = '0';
	game->map[y][x +1] = 'P';
	game->pos.x += 1;
	game->player.dir = RIGHT;
}

static void	left(t_games *game, int y, int x, int c)
{
	ft_patrouilles2(game);
	if (game->map[y][x - 1] == 'M')
	{
		ft_printf("you were hit by a fireball, you lost, try again");
		exit(EXIT_FAILURE);
	}
	if (game->map[y][x - 2] == 'C')
		incruster_img(game, game->objet2, x - 2, y);
	if (game->map[y][x - 1] == 'C')
	{
		c--;
		game->objets.collect = c;
	}
	if (game->map[y][x - 2] == 'E' && game->objets.collect == 0)
		incruster_img(game, game->exit2, x - 2, y);
	if (game->map[y][x - 1] == 'E' && game->objets.collect == 0)
		exit(EXIT_SUCCESS);
	if (game->map[y][x - 1] == 'E' && game->objets.collect != 0)
		return ;
	compteur_pas(game);
	game->map[y][x] = '0';
	game->map[y][x -1] = 'P';
	game->pos.x -= 1;
	game->player.dir = LEFT;
}

static void	up(t_games *game, int y, int x, int c)
{	
	ft_patrouilles2(game);
	if (game->map[y + 1][x] == 'M')
	{
		ft_printf("you were hit by a fireball, you lost, try again");
		exit(EXIT_FAILURE);
	}
	if (game->map[y + 2][x] == 'C')
		incruster_img(game, game->objet2, x, y + 2);
	if (game->map[y + 1][x] == 'C')
	{
		c--;
		game->objets.collect = c;
	}
	if (game->map[y + 2][x] == 'E' && game->objets.collect == 0)
		incruster_img(game, game->exit2, x, y + 2);
	if (game->map[y + 1][x] == 'E' && game->objets.collect == 0)
		exit(EXIT_SUCCESS);
	if (game->map[y + 1][x] == 'E' && game->objets.collect != 0)
		return ;
	compteur_pas(game);
	game->map[y][x] = '0';
	game->map[y +1][x] = 'P';
	game->pos.y += 1;
	game->player.dir = DOWN;
}

static void	down(t_games *game, int y, int x, int c)
{	
	ft_patrouilles2(game);
	if (game->map[y - 1][x] == 'M')
	{
		ft_printf("you were hit by a fireball, you lost, try again");
		exit(EXIT_FAILURE);
	}
	if (game->map[y - 2][x] == 'C')
		incruster_img(game, game->objet2, x, y - 2);
	if (game->map[y - 1][x] == 'C')
	{
		c--;
		game->objets.collect = c;
	}
	if (game->map[y - 2][x] == 'E' && game->objets.collect == 0)
		incruster_img(game, game->exit2, x, y - 2);
	if (game->map[y - 1][x] == 'E' && game->objets.collect == 0)
		exit(EXIT_SUCCESS);
	if (game->map[y - 1][x] == 'E' && game->objets.collect != 0)
		return ;
	compteur_pas(game);
	game->map[y][x] = '0';
	game->map[y -1][x] = 'P';
	game->pos.y -= 1;
	game->player.dir = UP;
}

int	moove_player(int touche, t_games *game)
{
	int	x;
	int	y;
	int	c;

	x = game->pos.x;
	y = game->pos.y;
	game->objets.collect = collectib_compteur(game, 'C');
	c = game->objets.collect;
	incruster_img(game, game->sol, game->pos.x, game->pos.y);
	if (touche == 2 && game->map[y][x + 1] != '1')
		right(game, y, x, c);
	else if (touche == 0 && game->map[y][x - 1] != '1')
		left(game, y, x, c);
	else if (touche == 1 && game->map[y + 1][x] != '1')
		up(game, y, x, c);
	else if (touche == 13 && game->map[y - 1][x] != '1')
		down(game, y, x, c);
	else if (touche == 53)
		exit(EXIT_FAILURE);
	incruster_img(game, game->sol, game->pos.x, game->pos.y);
	moove_player_dir(game);
	return (touche);
}
