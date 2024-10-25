/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:38:04 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/25 13:33:19 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_file_extention(t_loadgame *loadgame, char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strcmp(path + (len - 4), ".ber") != 0)
		throw_error("Error: Wrong file extention.", loadgame);
}

void	update_moves(t_loadgame *loadgame)
{
	loadgame->moves++;
	ft_printf("Current number of movements: %d\n", loadgame->moves);
}

char	**create_map_copy(t_loadgame *loadgame)
{
	char	**map_copy;
	int		y;

	y = 0;
	map_copy = malloc(sizeof(char *) * loadgame->height);
	if (!map_copy)
		exit_game_on_error("malloc", loadgame);
	while (y < loadgame->height)
	{
		map_copy[y] = ft_strdup(loadgame->map[y]);
		if (!map_copy[y])
			exit_game_on_error("malloc", loadgame);
		y++;
	}
	return (map_copy);
}

void	add_node(t_loadgame *loadgame, char *next_line)
{
	char	*line;
	t_list	*node;
	size_t	len;

	if (next_line[ft_strlen(next_line) - 1] == '\n')
		len = ft_strlen(next_line);
	else
		len = ft_strlen(next_line) + 1;
	line = malloc(len);
	if (!line)
		exit_game_on_error("malloc", loadgame);
	ft_strlcpy(line, next_line, len);
	free(next_line);
	node = ft_lstnew(line);
	if (!node)
		exit_game_on_error("malloc", loadgame);
	if (!loadgame->read_map)
		loadgame->read_map = node;
	else
		ft_lstadd_back(&loadgame->read_map, node);
}

void	get_player_start(t_loadgame *loadgame, int y)
{
	int	x;

	x = 0;
	loadgame->player_y = y;
	while (loadgame->map[y][x] != 'P')
		x++;
	loadgame->player_x = x;
}
