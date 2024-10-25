/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:11 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 20:40:29 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../mylib/ft_printf.h"
# include "../mylib/libft/libft.h"
# include <unistd.h>
# include <limits.h>

// # include <X11/X.h>
// # include <X11/keysym.h>
# include "../MLX42/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_WINDOW_WIDTH 1300
# define MAX_WINDOW_HEIGHT 900
# define MAX_TILE_WIDTH 13
# define MAX_TILE_HEIGHT 9
# define TILE_SIZE 100

typedef struct s_character
{
	mlx_image_t		*idle[11];
	mlx_image_t		*idle_left[11];
	int				frame;
}	t_character;

typedef struct s_dungeon
{
	mlx_image_t		*top;
	mlx_image_t		*bottom;
	mlx_image_t		*left;
	mlx_image_t		*right;
	mlx_image_t		*bottom_left;
	mlx_image_t		*bottom_right;
}	t_dungeon;

// Game data structure
typedef struct s_loadgame
{
	mlx_t			*mlx;
	int				fd;
	char			**map;
	t_list			*read_map;
	int				width;				
	int				height;
	int				player_x;
	int				player_y;
	int				collectibles;
	int				collectibles_collected;
	mlx_image_t		*background_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*collectible_img;
	mlx_image_t		*exit_img;
	t_character		*character;
	t_dungeon		*dungeon;
	int				current_frame;
	int				offset_x;
	int				offset_y;
	int				moves;
}	t_loadgame;

// Initialization functions
void	init_loadgame(t_loadgame *loadgame);
void	init_game(t_loadgame *game);
void	init_mlx(t_loadgame *loadgame);
void	init_map(t_loadgame *game);
void	init_textures(t_loadgame *game);
void	init_dungeon(t_loadgame *loadgame);
void	init_monster(t_loadgame *loadgame);
void	init_character(t_loadgame *loadgame);
void	init_character_idle(t_loadgame *loadgame);
void	init_character_idle_left(t_loadgame *loadgame);

// Character animation functions
void	load_character_idle(t_loadgame *loadgame);
void	load_character_idle_left(t_loadgame *loadgame);
void	load_sprite_sheet(mlx_image_t **frames, void *mlx,
			char *path, int num_frames);
void	character_attack_animation(t_loadgame *data);
void	character_idle_animation(t_loadgame *data);
void	character_idle_animation_2(t_loadgame *data);
void	character_idle_left_animation(t_loadgame *data);
void	character_idle_left_animation_2(t_loadgame *data);
void	character_idle_left_animation_3(t_loadgame *data);

// Parsing functions
void	parse_map(t_loadgame *loadgame);
int		read_map(t_loadgame *loadgame);
void	add_node(t_loadgame *loadgame, char *next_line);
int		store_map(t_loadgame *loadgame);
int		is_map_valid(t_loadgame *loadgame);
int		all_char_present(t_loadgame *loadgame);
void	get_player_start(t_loadgame *loadgame, int y);
void	is_path_valid(t_loadgame *loadgame, char **map);
void	flood_fill(t_loadgame *loadgame, char **map, int y, int x);
char	**create_map_copy(t_loadgame *loadgame);
int		count_chars(t_loadgame *loadgame, char *line, char c);
void	check_file_extention(t_loadgame *loadgame, char *path);

// Drawing functions
void	draw_map(t_loadgame *loadgame);
void	draw_sprite(t_loadgame *loadgame, int x, int y);
void	draw_wall(t_loadgame *loadgame, int x, int y);
void	draw_inner_wall(t_loadgame *loadgame, int x, int y);
void	draw_background(t_loadgame *loadgame, int x, int y);
void	draw_character(t_loadgame *loadgame, int x, int y);
void	draw_collectible(t_loadgame *loadgame, int x, int y);
void	draw_monster(t_loadgame *loadgame, int x, int y);
void	draw_exit(t_loadgame *loadgame, int x, int y);

// Loading images
void	load_images(t_loadgame *loadgame);
void	load_sprite(mlx_image_t **sprite, void *mlx, char *path);
void	load_dungeon(t_loadgame *loadgame);
void	verify_dungeon(t_loadgame *loadgame);
void	verify_textures(t_loadgame *loadgame, mlx_image_t *sprites[11]);

// Hooks and key handling
void	setup_hooks(t_loadgame *loadgame);
void	key_hook(mlx_key_data_t keydata, void *param);
void	get_new_coords(mlx_key_data_t keydata, t_loadgame *data,
			int *new_x, int *new_y);
void	move_character(t_loadgame *data, int new_x, int new_y);
void	interactive_cell(t_loadgame *data, int new_x, int new_y);

// Game loop
void	game_loop(void *param);

// Camera functions
void	move_camera(t_loadgame *loadgame);
int		is_player_in_camera(t_loadgame *loadgame, int player_x, int player_y);
void	adjust_offset_x(t_loadgame *loadgame);
void	adjust_offset_y(t_loadgame *loadgame);

// Utility functions
char	*get_next_line(int fd);
void	update_moves(t_loadgame *loadgame);
void	throw_error(char *message, t_loadgame *loadgame);
void	free_all(t_loadgame *loadgame);
void	free_map(char **map, int length);

// Exit functions
void	exit_game(void *param);
void	exit_game_on_error(char *message, t_loadgame *loadgame);

#endif