/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:53:59 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/13 15:16:44 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define DOWN 3
# define LEFT 1
# define RIGHT 2
# define UP 0

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "utils/libft/libft.h"

typedef struct s_axes
{
	int	y;
	int	x;
}	t_axes;

typedef struct s_picture
{
	void	*reference;
	char	*img;
	int		width;
	int		height;
	t_axes	pos;
	int		collect;
}	t_picture;

typedef struct s_player
{
	void		*down;
	void		*right;
	void		*left;
	void		*up;
	t_axes		size;
	t_picture	players;
	t_picture	playerw;
	t_picture	playera;
	t_picture	playerd;
	int			dir;
}	t_player;

typedef struct s_windows
{
	void	*reference;
	t_axes	size;

}	t_windows;

typedef struct s_games
{
	char		**map;
	t_windows	window;
	void		*mlx;
	t_axes		axes;
	t_player	player;
	t_axes		wall_position;
	t_axes		pos;
	t_picture	sol;
	t_picture	mur;
	t_picture	joueur;
	t_picture	objet1;
	t_picture	objets;
	t_picture	objet2;
	t_picture	fireball;
	t_picture	exit;
	t_picture	*mon;
	t_picture	pmo;
	t_picture	exit2;
	int			pas;
	int			nbr;
	int			modification;
	char		**cpy_map;
	int			monstres;
}	t_games;

//FONCTIONS SRC

void	up_mst(t_games *game, int i);
void	gauche_mst(t_games *game, int i);
void	down_mst(t_games *game, int i);
void	droite_mst(t_games *game, int i);

void	good_way(t_games *game);
void	verif_way(t_games *game);

char	**copy_map(t_games *game, char **str);
void	ft_map(const char *files, t_games *game);
void	size_map(t_games *game, const char *files);
void	ft_character(t_games *game);

void	ft_patrouilles2(t_games *game);

void	compteur_pas(t_games *game);

void	ft_error(char *str);
void	ft_exit_map(t_games *game);
void	ft_square(t_games *game);
void	ft_min_collect(t_games *game);
int		collectib_compteur(t_games *game, char m);

int		moove_player(int touche, t_games *game);

void	incruster_img(t_games *game, t_picture picture, int x, int y);
void	stock_image(t_games *game);

void	moove_player_dir(t_games *game);
void	structure_init_x(t_games *game);
void	structure_init_y(t_games *game);
void	free_string(char **str);
int		ft_search_c(char **map, char c);

void	condition_1(t_games *game, char **map, int x, int y);
void	condition_2(t_games *game, char **map, int x, int y);
void	condition_3(t_games *game, char **map, int x, int y);
void	condition_4(t_games *game, char **map, int x, int y);

#endif
