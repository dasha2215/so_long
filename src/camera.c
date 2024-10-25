/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:10:37 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:11:31 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_player_in_camera(t_loadgame *loadgame, int player_x, int player_y)
{
	int	camera_x_start;
	int	camera_x_end;
	int	camera_y_start;
	int	camera_y_end;

	camera_x_start = loadgame->offset_x;
	camera_x_end = loadgame->offset_x + MAX_TILE_WIDTH;
	camera_y_start = loadgame->offset_y;
	camera_y_end = loadgame->offset_y + MAX_TILE_HEIGHT;
	if (player_x >= camera_x_start && player_x < camera_x_end
		&& player_y >= camera_y_start && player_y < camera_y_end)
		return (1);
	return (0);
}

void	move_camera(t_loadgame *loadgame)
{
	loadgame->offset_x = loadgame->player_x - MAX_TILE_WIDTH / 2;
	loadgame->offset_y = loadgame->player_y - MAX_TILE_HEIGHT / 2;
	if (loadgame->offset_x < 0)
		loadgame->offset_x = 0;
	if (loadgame->offset_y < 0)
		loadgame->offset_y = 0;
	if (loadgame->offset_x != 0)
		adjust_offset_x(loadgame);
	if (loadgame->offset_y != 0)
		adjust_offset_y(loadgame);
}

void	adjust_offset_x(t_loadgame *loadgame)
{
	int	limit;

	limit = (loadgame->width - 1)
		- (loadgame->player_x + MAX_TILE_WIDTH / 2);
	if (limit < 0)
		loadgame->offset_x = loadgame->offset_x + limit;
	limit = loadgame->player_x - MAX_TILE_WIDTH / 2;
	if (limit < 0)
		loadgame->offset_x = loadgame->offset_x - limit;
}

void	adjust_offset_y(t_loadgame *loadgame)
{
	int	limit;

	limit = (loadgame->height - 1)
		- (loadgame->player_y + MAX_TILE_HEIGHT / 2);
	if (limit < 0)
		loadgame->offset_y = loadgame->offset_y + limit;
	limit = loadgame->player_y - MAX_TILE_HEIGHT / 2;
	if (limit < 0)
		loadgame->offset_y = loadgame->offset_y - limit;
}
