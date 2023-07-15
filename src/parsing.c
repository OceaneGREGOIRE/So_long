/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:15:06 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/13 14:25:23 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(char *str)
{
	write(2, "ERROR\n", 6);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void	ft_exit_map(t_games *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = game->axes.x - 1;
	y = game->axes.y - 1;
	i = 0;
	while (game->map[i] != NULL)
	{	
		j = 0;
		while (game->map[i][j] != '\n')
		{
			if (game->map[0][j] != '1' || game->map[y][j] != '1')
				ft_error("the map is not framed by walls");
			if (game->map[i][0] != '1' || game->map[i][x] != '1')
				ft_error("the map is not framed by walls");
			j++;
		}
		i++;
	}
}

void	ft_square(t_games *game)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	temp = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
			j++;
		if (j != temp)
			ft_error("the map is not rectangular");
		i++;
	}
}

int	collectib_compteur(t_games *game, char m)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == m)
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

void	ft_min_collect(t_games *game)
{
	if (collectib_compteur(game, 'E') != 1)
		ft_error("error : exit");
	if (collectib_compteur(game, 'P') != 1)
		ft_error("error : player");
	if (collectib_compteur(game, 'C') < 1)
		ft_error("error : not enough collectib");
}
