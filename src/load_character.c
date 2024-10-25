/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:19:33 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 20:25:52 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_character_idle(t_loadgame *loadgame)
{
	loadgame->character->idle[0] = NULL;
	loadgame->character->idle[1] = NULL;
	loadgame->character->idle[2] = NULL;
	loadgame->character->idle[3] = NULL;
	loadgame->character->idle[4] = NULL;
	loadgame->character->idle[5] = NULL;
	loadgame->character->idle[6] = NULL;
	loadgame->character->idle[7] = NULL;
	loadgame->character->idle[8] = NULL;
	loadgame->character->idle[9] = NULL;
	loadgame->character->idle[10] = NULL;
}

void	init_character_idle_left(t_loadgame *loadgame)
{
	loadgame->character->idle_left[0] = NULL;
	loadgame->character->idle_left[1] = NULL;
	loadgame->character->idle_left[2] = NULL;
	loadgame->character->idle_left[3] = NULL;
	loadgame->character->idle_left[4] = NULL;
	loadgame->character->idle_left[5] = NULL;
	loadgame->character->idle_left[6] = NULL;
	loadgame->character->idle_left[7] = NULL;
	loadgame->character->idle_left[8] = NULL;
	loadgame->character->idle_left[9] = NULL;
	loadgame->character->idle_left[10] = NULL;
}

void	load_character_idle(t_loadgame *loadgame)
{
	load_sprite(&loadgame->character->idle[0], loadgame->mlx,
		"textures/character/idle/0.png");
	load_sprite(&loadgame->character->idle[1], loadgame->mlx,
		"textures/character/idle/1.png");
	load_sprite(&loadgame->character->idle[2], loadgame->mlx,
		"textures/character/idle/2.png");
	load_sprite(&loadgame->character->idle[3], loadgame->mlx,
		"textures/character/idle/3.png");
	load_sprite(&loadgame->character->idle[4], loadgame->mlx,
		"textures/character/idle/4.png");
	load_sprite(&loadgame->character->idle[5], loadgame->mlx,
		"textures/character/idle/5.png");
	load_sprite(&loadgame->character->idle[6], loadgame->mlx,
		"textures/character/idle/6.png");
	load_sprite(&loadgame->character->idle[7], loadgame->mlx,
		"textures/character/idle/7.png");
	load_sprite(&loadgame->character->idle[8], loadgame->mlx,
		"textures/character/idle/8.png");
	load_sprite(&loadgame->character->idle[9], loadgame->mlx,
		"textures/character/idle/9.png");
	load_sprite(&loadgame->character->idle[10], loadgame->mlx,
		"textures/character/idle/10.png");
	verify_textures(loadgame, loadgame->character->idle);
}

void	load_character_idle_left(t_loadgame *loadgame)
{
	load_sprite(&loadgame->character->idle_left[0], loadgame->mlx,
		"textures/character/idle-left/0.png");
	load_sprite(&loadgame->character->idle_left[1], loadgame->mlx,
		"textures/character/idle-left/1.png");
	load_sprite(&loadgame->character->idle_left[2], loadgame->mlx,
		"textures/character/idle-left/2.png");
	load_sprite(&loadgame->character->idle_left[3], loadgame->mlx,
		"textures/character/idle-left/3.png");
	load_sprite(&loadgame->character->idle_left[4], loadgame->mlx,
		"textures/character/idle-left/4.png");
	load_sprite(&loadgame->character->idle_left[5], loadgame->mlx,
		"textures/character/idle-left/5.png");
	load_sprite(&loadgame->character->idle_left[6], loadgame->mlx,
		"textures/character/idle-left/6.png");
	load_sprite(&loadgame->character->idle_left[7], loadgame->mlx,
		"textures/character/idle-left/7.png");
	load_sprite(&loadgame->character->idle_left[8], loadgame->mlx,
		"textures/character/idle-left/8.png");
	load_sprite(&loadgame->character->idle_left[9], loadgame->mlx,
		"textures/character/idle-left/9.png");
	load_sprite(&loadgame->character->idle_left[10], loadgame->mlx,
		"textures/character/idle-left/10.png");
	verify_textures(loadgame, loadgame->character->idle_left);
}
