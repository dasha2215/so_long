/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:55:49 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 17:31:44 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	store_map(t_loadgame *loadgame)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = loadgame->read_map;
	loadgame->map = malloc(sizeof(char *) * loadgame->height);
	if (!loadgame->map)
		exit_game_on_error("malloc", loadgame);
	while (ptr)
	{
		loadgame->map[i] = ft_strdup(ptr->content);
		if (!loadgame->map[i])
			exit_game_on_error("malloc", loadgame);
		i++;
		ptr = ptr->next;
	}
	return (1);
}

// opens and reads map file, saves map into linked list
int	read_map(t_loadgame *loadgame)
{
	char	*next_line;

	while (1)
	{
		next_line = get_next_line(loadgame->fd);
		if (!next_line)
			break ;
		add_node(loadgame, next_line);
		if (loadgame->read_map && !loadgame->width)
			loadgame->width = ft_strlen(loadgame->read_map->content);
		next_line = NULL;
		loadgame->height++;
	}
	if (!loadgame->read_map)
		throw_error("Error: Couldn't open map or file is empty.", loadgame);
	return (1);
}

void	parse_map(t_loadgame *loadgame)
{
	char	**map_copy;

	read_map(loadgame);
	store_map(loadgame);
	is_map_valid(loadgame);
	all_char_present(loadgame);
	map_copy = create_map_copy(loadgame);
	flood_fill(loadgame, map_copy, loadgame->player_y, loadgame->player_x);
	is_path_valid(loadgame, map_copy);
	free_map(map_copy, loadgame->height);
	close(loadgame->fd);
	loadgame->fd = -1;
}
