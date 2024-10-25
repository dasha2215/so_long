/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:43:25 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:03:35 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	character_idle_animation(t_loadgame *data)
{
	mlx_image_to_window(data->mlx,
		data->character->idle[data->character->frame],
		(data->player_x - data->offset_x) * TILE_SIZE,
		((data->player_y - data->offset_y) * TILE_SIZE) - 50);
	if (data->map[data->player_y][data->player_x] == 'E')
		draw_exit(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y);
	else
		draw_background(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y);
	if (data->map[data->player_y - 1][data->player_x] == '1')
		draw_wall(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
		draw_collectible(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x] == 'E')
		draw_exit(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else
		draw_background(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	character_idle_animation_2(data);
	data->character->frame = (data->character->frame + 1) % 11;
}

void	character_idle_animation_2(t_loadgame *data)
{
	if (data->map[data->player_y - 1][data->player_x + 1] == '1')
		draw_wall(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x + 1] == 'C')
		draw_collectible(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x + 1] == 'E')
		draw_exit(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else
		draw_background(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
}

void	character_idle_left_animation(t_loadgame *data)
{
	mlx_image_to_window(data->mlx,
		data->character->idle_left[data->character->frame],
		(data->player_x - data->offset_x) * TILE_SIZE,
		((data->player_y - data->offset_y) * TILE_SIZE) - 50);
	if (data->map[data->player_y][data->player_x] == 'E')
		draw_exit(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y);
	else
		draw_background(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y);
	if (data->map[data->player_y - 1][data->player_x] == '1')
		draw_wall(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x] == 'C')
		draw_collectible(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x] == 'E')
		draw_exit(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	else
		draw_background(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y - 1);
	character_idle_left_animation_2(data);
	character_idle_left_animation_3(data);
	data->character->frame = (data->character->frame + 1) % 11;
}

void	character_idle_left_animation_2(t_loadgame *data)
{
	if (data->map[data->player_y - 1][data->player_x - 1] == '1')
		draw_wall(data, data->player_x - data->offset_x - 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x - 1] == 'C')
		draw_collectible(data, data->player_x - data->offset_x - 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x - 1] == 'E')
		draw_exit(data, data->player_x - data->offset_x - 1,
			data->player_y - data->offset_y - 1);
	else
		draw_background(data, data->player_x - data->offset_x - 1,
			data->player_y - data->offset_y - 1);
	if (data->map[data->player_y - 1][data->player_x + 1] == '1')
		draw_wall(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x + 1] == 'C')
		draw_collectible(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else if (data->map[data->player_y - 1][data->player_x + 1] == 'E')
		draw_exit(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
	else
		draw_background(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y - 1);
}

void	character_idle_left_animation_3(t_loadgame *data)
{
	if (data->map[data->player_y][data->player_x + 1] == '1')
		draw_wall(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y);
	else if (data->map[data->player_y][data->player_x + 1] == 'C')
		draw_collectible(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y);
	else if (data->map[data->player_y][data->player_x + 1] == 'E')
		draw_exit(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y);
	else
		draw_background(data, data->player_x - data->offset_x + 1,
			data->player_y - data->offset_y);
}
