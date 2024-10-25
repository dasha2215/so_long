/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:13:47 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:12:07 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_inner_wall(t_loadgame *loadgame, int x, int y)
{
	mlx_image_to_window(loadgame->mlx, loadgame->wall_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_background(t_loadgame *loadgame, int x, int y)
{
	mlx_image_to_window(loadgame->mlx, loadgame->background_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_exit(t_loadgame *loadgame, int x, int y)
{
	draw_background(loadgame, x, y);
	mlx_image_to_window(loadgame->mlx, loadgame->exit_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_character(t_loadgame *loadgame, int x, int y)
{
	draw_background(loadgame, x, y);
	if (loadgame->map[y + loadgame->offset_y][x + loadgame->offset_x] == 'E')
	{
		draw_exit(loadgame, x, y);
	}
	if (loadgame->current_frame == 0)
		mlx_image_to_window(loadgame->mlx, loadgame->character->idle_left[0],
			x * TILE_SIZE, (y * TILE_SIZE) - 50);
	else
		mlx_image_to_window(loadgame->mlx, loadgame->character->idle[0],
			x * TILE_SIZE, (y * TILE_SIZE) - 50);
	loadgame->character->frame = (loadgame->character->frame + 1) % 11;
}

void	draw_collectible(t_loadgame *loadgame, int x, int y)
{
	draw_background(loadgame, x, y);
	mlx_image_to_window(loadgame->mlx, loadgame->collectible_img,
		x * TILE_SIZE, y * TILE_SIZE);
}
