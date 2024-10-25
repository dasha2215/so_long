/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:04:58 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:05:14 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_valid(t_loadgame *loadgame)
{
	int		i;
	int		j;

	i = 0;
	while (i < loadgame->height)
	{
		if ((int)ft_strlen(loadgame->map[i]) != loadgame->width)
			throw_error("Error: Invalid map.", loadgame);
		j = 0;
		while (j < loadgame->width)
		{
			if (!ft_strchr("01CEPM", loadgame->map[i][j]))
				throw_error("Error: Invalid map.", loadgame);
			if ((j == 0 || i == 0 || j == loadgame->width - 1
					|| i == loadgame->height - 1)
				&& (loadgame->map[i][j] != '1'))
				throw_error("Error: Invalid map.", loadgame);
			j++;
		}
		i++;
	}
	return (1);
}

int	all_char_present(t_loadgame *loadgame)
{
	int		chars[3];
	int		i;

	i = 0;
	chars[0] = 0;
	chars[1] = 0;
	chars[2] = 0;
	while (i < loadgame->height)
	{
		if (ft_strchr(loadgame->map[i], 'P'))
			if (!chars[0])
				get_player_start(loadgame, i);
		chars[0] += count_chars(loadgame, loadgame->map[i], 'P');
		chars[1] += count_chars(loadgame, loadgame->map[i], 'C');
		chars[2] += count_chars(loadgame, loadgame->map[i], 'E');
		i++;
	}
	if (chars[0] != 1 || chars[2] != 1 || chars[1] < 1)
		throw_error("Error: Invalid map.", loadgame);
	loadgame->collectibles = chars[1];
	return (1);
}

int	count_chars(t_loadgame *loadgame, char *line, char c)
{
	int	count;
	int	x;

	x = 0;
	count = 0;
	while (x < loadgame->width)
	{
		if (line[x] == c)
			count++;
		x++;
	}
	return (count);
}

void	is_path_valid(t_loadgame *loadgame, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (y < loadgame->height)
	{
		x = 0;
		while (x < loadgame->width)
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				free_map(map, loadgame->height);
				throw_error("Error: Invalid map.", loadgame);
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_loadgame *loadgame, char **map, int y, int x)
{
	if (x < 0 || y < 0 || x >= loadgame->width || y >= loadgame->height)
		return ;
	if (map[y][x] == 'X' || map[y][x] == '1')
		return ;
	map[y][x] = 'X';
	flood_fill(loadgame, map, y + 1, x);
	flood_fill(loadgame, map, y - 1, x);
	flood_fill(loadgame, map, y, x + 1);
	flood_fill(loadgame, map, y, x - 1);
}
