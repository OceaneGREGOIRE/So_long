/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:11:50 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/13 14:14:44 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	incruster_img(t_games *game, t_picture picture, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window.reference, \
			picture.reference, x * 64, y * 64);
}

static t_picture	pre_path(t_games *game, char *path)
{
	t_picture	picture;

	picture.reference = mlx_xpm_file_to_image(game->mlx, path, \
			&picture.width, &picture.height);
	return (picture);
}

static void	path(t_games *game)
{
	game->sol = pre_path(game, "./image_source/sol.xpm");
	game->exit = pre_path(game, "./image_source/grotte.xpm");
	game->joueur = pre_path(game, "./image_source/players.xpm");
	game->mur = pre_path(game, "./image_source/mur.xpm");
	game->objet1 = pre_path(game, "./image_source/pokeball1.xpm");
	game->objet2 = pre_path(game, "./image_source/pokeball2.xpm");
	game->player.players = pre_path(game, "./image_source/players.xpm");
	game->player.playerw = pre_path(game, "./image_source/playerw.xpm");
	game->player.playera = pre_path(game, "./image_source/playera.xpm");
	game->player.playerd = pre_path(game, "./image_source/playerd.xpm");
	game->pmo = pre_path(game, "./image_source/monsters.xpm");
	game->fireball = pre_path(game, "./image_source/fireball.xpm");
	game->exit2 = pre_path(game, "./image_source/grotte2.xpm");
}

static void	p(t_games *game, int i, int j)
{
	game->player.dir = DOWN;
	game->pos.x = j;
	game->pos.y = i;
	moove_player_dir(game);
}

void	stock_image(t_games *game)
{
	int	i;
	int	j;

	i = 0;
	path(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			incruster_img(game, game->sol, j, i);
			if (game->map[i][j] == '1')
				incruster_img(game, game->mur, j, i);
			else if (game->map[i][j] == 'P')
				p(game, i, j);
			else if (game->map[i][j] == 'C')
				incruster_img(game, game->objet1, j, i);
			else if (game->map[i][j] == 'E')
				incruster_img(game, game->exit, j, i);
			else if (game->map[i][j] == 'M')
				incruster_img(game, game->pmo, j, i);
			j++;
		}
		i++;
	}
}
