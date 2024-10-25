/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:54:34 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 19:35:50 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_loop(void *param)
{
	t_loadgame	*data;

	data = (t_loadgame *)param;
	if (data->current_frame == 1)
		character_idle_animation(data);
	else
		character_idle_left_animation(data);
	usleep(80000);
}

int	main(int argc, char **argv)
{
	t_loadgame	*loadgame;

	loadgame = malloc(sizeof(t_loadgame));
	if (!loadgame)
		exit_game_on_error("malloc", NULL);
	init_loadgame(loadgame);
	if (argc != 2)
		throw_error("Error: Provide one map path.", loadgame);
	check_file_extention(loadgame, argv[1]);
	loadgame->fd = open(argv[1], O_RDONLY);
	if (loadgame->fd < 0)
		throw_error("Error: Couldn't open map or file is empty.", loadgame);
	parse_map(loadgame);
	init_mlx(loadgame);
	load_images(loadgame);
	init_dungeon(loadgame);
	init_character(loadgame);
	draw_map(loadgame);
	mlx_key_hook(loadgame->mlx, key_hook, loadgame);
	mlx_close_hook(loadgame->mlx, exit_game, loadgame);
	mlx_loop_hook(loadgame->mlx, game_loop, loadgame);
	mlx_loop(loadgame->mlx);
	mlx_terminate(loadgame->mlx);
	free_all(loadgame);
	exit(EXIT_SUCCESS);
}
