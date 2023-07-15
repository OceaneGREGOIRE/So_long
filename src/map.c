/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:23:24 by ogregoir          #+#    #+#             */
/*   Updated: 2023/06/13 14:00:28 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_character(t_games *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' && \
			game->map[i][j] != 'M' && game->map[i][j] != 'C' && \
			game->map[i][j] != 'E' && game->map[i][j] != 'P' && \
			game->map[i][j] != '\n')
				ft_error("caracter is not valid");
			j++;
		}
		i++;
	}
}

char	**copy_map(t_games *game, char **str)
{
	int		i;
	char	**s;

	s = malloc(sizeof(char *) * (game->axes.y + 1));
	i = 0;
	while (str[i])
	{
		s[i] = ft_strdup(str[i]);
		i++;
	}
	s[i] = NULL;
	return (s);
}

void	size_map(t_games *game, const char *files)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	game->axes.y = 0;
	fd = open(files, O_RDONLY);
	str = get_next_line(fd);
	if (!str)
		ft_error("EMPTY MAP");
	while (str[i])
		i++;
	game->axes.x = i - 1;
	while (str != NULL)
	{
		game->axes.y++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	ft_map(const char *files, t_games *game)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(files, O_RDONLY);
	game->map = malloc((sizeof(char *) * (game->axes.y +1)) + 1);
	game->map[i] = get_next_line(fd);
	while (game->map[i] != '\0')
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	close(fd);
	game->map[i -1] = ft_strjoin_free(game->map[i - 1], "\n");
}
