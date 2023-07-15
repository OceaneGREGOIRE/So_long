/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:26:12 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/19 21:45:39 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	verif_ber(char *argv)
{
	int		i;

	i = ft_strlen(argv);
	if (i < 5)
		ft_error("error map.ber");
	if (!ft_strrchr(argv, '.') || \
	ft_strncmp(ft_strrchr(argv, '.'), ".ber", 5) != 0)
		ft_error("error map.ber");
	if (!ft_strrchr(argv, '.') || \
	ft_strncmp(ft_strrchr(argv, '.'), argv, 5) == 0)
		ft_error("error map.ber");
	if (ft_strrchr(argv, '.') && ft_strrchr(argv, '/') && \
		ft_strncmp(ft_strrchr(argv, '.'), ft_strrchr(argv, '/') + 1, 5) == 0)
		ft_error("error map.ber");
}

static int	ft_exit(t_games *game)
{
	(void)game;
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_games	game;

	if (argc != 2)
		exit(EXIT_FAILURE);
	game.mlx = mlx_init();
	verif_ber(argv[1]);
	size_map(&game, argv[1]);
	ft_map(argv[1], &game);
	ft_square(&game);
	ft_character(&game);
	ft_exit_map(&game);
	ft_min_collect(&game);
	verif_way(&game);
	game.mon = malloc(sizeof(t_picture) * 1);
	game.window.reference = \
			mlx_new_window(game.mlx, game.axes.x * 64, game.axes.y * 64, "MAP");
	stock_image(&game);
	mlx_key_hook(game.window.reference, moove_player, &game);
	mlx_hook(game.window.reference, 17, 0L, ft_exit, &game);
	mlx_loop(&game);
	free_string(game.map);
}
