/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:44:24 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 20:20:16 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_loadgame *loadgame)
{
	load_sprite(&loadgame->background_img, loadgame->mlx, "textures/back.png");
	load_sprite(&loadgame->wall_img, loadgame->mlx, "textures/wall.png");
	load_sprite(&loadgame->collectible_img, loadgame->mlx,
		"textures/collectible.png");
	load_sprite(&loadgame->exit_img, loadgame->mlx, "textures/exit.png");
	if (!loadgame->background_img || !loadgame->wall_img)
		throw_error("Error: Failed to load textures.", loadgame);
}

void	load_dungeon(t_loadgame *loadgame)
{
	load_sprite(&loadgame->dungeon->top, loadgame->mlx,
		"textures/dungeon/top.png");
	load_sprite(&loadgame->dungeon->bottom, loadgame->mlx,
		"textures/dungeon/bottom.png");
	load_sprite(&loadgame->dungeon->left, loadgame->mlx,
		"textures/dungeon/left.png");
	load_sprite(&loadgame->dungeon->right, loadgame->mlx,
		"textures/dungeon/right.png");
	load_sprite(&loadgame->dungeon->bottom_left, loadgame->mlx,
		"textures/dungeon/bottom-left.png");
	load_sprite(&loadgame->dungeon->bottom_right, loadgame->mlx,
		"textures/dungeon/bottom-right.png");
}

void	verify_dungeon(t_loadgame *loadgame)
{
	if (!loadgame->dungeon->top)
		throw_error("Error: Failed to load textures.", loadgame);
	if (!loadgame->dungeon->bottom)
		throw_error("Error: Failed to load textures.", loadgame);
	if (!loadgame->dungeon->bottom_left)
		throw_error("Error: Failed to load textures.", loadgame);
	if (!loadgame->dungeon->bottom_right)
		throw_error("Error: Failed to load textures.", loadgame);
	if (!loadgame->dungeon->left)
		throw_error("Error: Failed to load textures.", loadgame);
	if (!loadgame->dungeon->right)
		throw_error("Error: Failed to load textures.", loadgame);
}

void	load_sprite(mlx_image_t **sprite, void *mlx, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		return ;
	*sprite = mlx_texture_to_image(mlx, texture);
	if (!sprite)
		return ;
	mlx_delete_texture(texture);
}

void	verify_textures(t_loadgame *loadgame, mlx_image_t *sprites[11])
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (!sprites[i])
			throw_error("Error: Failed to load textures.", loadgame);
		i++;
	}
}
