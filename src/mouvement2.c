/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:49:29 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/19 19:49:59 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	compteur_pas(t_games *game)
{
	char	*str;

	game->pas++;
	ft_printf("%d", game->pas);
	write (1, "\n", 1);
	str = ft_itoa(game->pas);
	incruster_img(game, game->mur, 0, 0);
	mlx_string_put(game->mlx, game->window.reference, 8, 5, 000000, str);
	free(str);
}
