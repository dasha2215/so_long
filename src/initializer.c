/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:32:11 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 20:23:18 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_loadgame(t_loadgame *loadgame)
{
	loadgame->mlx = NULL;
	loadgame->fd = -1;
	loadgame->map = NULL;
	loadgame->read_map = NULL;
	loadgame->height = 0;
	loadgame->width = 0;
	loadgame->player_x = 0;
	loadgame->player_y = 0;
	loadgame->collectibles = 0;
	loadgame->background_img = NULL;
	loadgame->wall_img = NULL;
	loadgame->collectible_img = NULL;
	loadgame->exit_img = NULL;
	loadgame->character = NULL;
	loadgame->dungeon = NULL;
	loadgame->current_frame = 0;
	loadgame->offset_x = 0;
	loadgame->offset_y = 0;
	loadgame->collectibles_collected = 0;
	loadgame->moves = 0;
}

void	init_mlx(t_loadgame *loadgame)
{
	int	width;
	int	height;

	if (loadgame->width * TILE_SIZE > MAX_WINDOW_WIDTH)
		width = MAX_WINDOW_WIDTH;
	else
		width = loadgame->width * TILE_SIZE;
	if (loadgame->height * TILE_SIZE > MAX_WINDOW_HEIGHT)
		height = MAX_WINDOW_HEIGHT;
	else
		height = loadgame->height * TILE_SIZE;
	loadgame->mlx = mlx_init(width, height, "so_long", true);
	if (!loadgame->mlx)
		return ;
}

void	init_dungeon(t_loadgame *loadgame)
{
	loadgame->dungeon = malloc(sizeof(t_dungeon));
	if (!loadgame->dungeon)
		exit_game_on_error("malloc", loadgame);
	loadgame->dungeon->top = NULL;
	loadgame->dungeon->bottom = NULL;
	loadgame->dungeon->bottom_left = NULL;
	loadgame->dungeon->bottom_right = NULL;
	loadgame->dungeon->left = NULL;
	loadgame->dungeon->right = NULL;
	load_dungeon(loadgame);
	verify_dungeon(loadgame);
}

void	init_character(t_loadgame *loadgame)
{
	loadgame->character = malloc(sizeof(t_character));
	if (!loadgame->character)
		exit_game_on_error("malloc", loadgame);
	init_character_idle(loadgame);
	init_character_idle_left(loadgame);
	if (loadgame->player_x + 1 < loadgame->width
		&& loadgame->map[loadgame->player_y][loadgame->player_x + 1] != '1')
		loadgame->current_frame = 1;
	else
		loadgame->current_frame = 0;
	load_character_idle(loadgame);
	load_character_idle_left(loadgame);
	loadgame->character->frame = 0;
}
