/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:13:22 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:12:16 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_loadgame *loadgame)
{
	int	x;
	int	y;

	y = 0;
	move_camera(loadgame);
	while (y < loadgame->mlx->height / TILE_SIZE)
	{
		x = 0;
		while (x < loadgame->mlx->width / TILE_SIZE)
		{
			draw_sprite(loadgame, x, y);
			x++;
		}
		y++;
	}
}

void	draw_sprite(t_loadgame *loadgame, int x, int y)
{
	if (loadgame->map[y + loadgame->offset_y][x + loadgame->offset_x]
		== '1')
		draw_wall(loadgame, x, y);
	else if (loadgame->map[y + loadgame->offset_y]
		[x + loadgame->offset_x] == '0')
		draw_background(loadgame, x, y);
	else if (loadgame->map[y + loadgame->offset_y]
		[x + loadgame->offset_x] == 'C')
		draw_collectible(loadgame, x, y);
	else if (loadgame->map[y + loadgame->offset_y]
		[x + loadgame->offset_x] == 'E')
		draw_exit(loadgame, x, y);
	draw_character(loadgame, loadgame->player_x - loadgame->offset_x,
		loadgame->player_y - loadgame->offset_y);
}

void	draw_wall(t_loadgame *loadgame, int x, int y)
{
	int	draw_x;
	int	draw_y;

	draw_x = x + loadgame->offset_x;
	draw_y = y + loadgame->offset_y;
	if (draw_x == 0 && draw_y == loadgame->height - 1)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->bottom_left,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (draw_x == loadgame->width - 1 && draw_y == loadgame->height - 1)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->bottom_right,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (draw_y == 0 && draw_x != 0 && draw_x != loadgame->width - 1)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->top,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (draw_x == 0)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->left,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (draw_y == loadgame->height - 1)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->bottom,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (draw_x == loadgame->width - 1)
		mlx_image_to_window(loadgame->mlx, loadgame->dungeon->right,
			x * TILE_SIZE, y * TILE_SIZE);
	else
		draw_inner_wall(loadgame, x, y);
}
