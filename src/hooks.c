/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 13:53:37 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 21:04:02 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_loadgame	*data;
	int			new_x;
	int			new_y;

	data = (t_loadgame *)param;
	new_x = data->player_x;
	new_y = data->player_y;
	if (keydata.action == MLX_PRESS)
	{
		get_new_coords(keydata, data, &new_x, &new_y);
		move_character(data, new_x, new_y);
	}
}

void	get_new_coords(mlx_key_data_t keydata, t_loadgame *data,
		int *new_x, int *new_y)
{
	if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(data);
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		(*new_x)++;
		data->current_frame = 1;
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		(*new_x)--;
		data->current_frame = 0;
	}
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		(*new_y)--;
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		(*new_y)++;
	else if (keydata.key == MLX_KEY_X)
	{
		data->character->frame = 0;
		return ;
	}
}

void	move_character(t_loadgame *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] != '1'
		&& data->map[new_y][new_x] != 'M')
	{
		update_moves(data);
		if (data->map[data->player_y][data->player_x] != 'E')
			draw_background(data, data->player_x - data->offset_x,
				data->player_y - data->offset_y);
		else
			draw_exit(data, data->player_x - data->offset_x,
				data->player_y - data->offset_y);
		if (data->map[data->player_y][data->player_x] == 'P')
			data->map[data->player_y][data->player_x] = '0';
		data->player_x = new_x;
		data->player_y = new_y;
		if (!is_player_in_camera(data, data->player_x, data->player_y))
			draw_map(data);
		interactive_cell(data, new_x, new_y);
		draw_character(data, data->player_x - data->offset_x,
			data->player_y - data->offset_y);
	}
	else if (data->map[new_y][new_x] == '1')
	{
		if (!is_player_in_camera(data, new_x, new_y))
			draw_map(data);
	}
}

void	interactive_cell(t_loadgame *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'C')
	{
		data->collectibles_collected++;
		data->map[new_y][new_x] = '0';
	}
	if (data->map[new_y][new_x] == 'E')
	{
		if (data->collectibles_collected == data->collectibles)
		{
			update_moves(data);
			exit_game(data);
		}
	}
}
