/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsiroten <dsiroten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:54:37 by dsiroten          #+#    #+#             */
/*   Updated: 2024/07/05 17:53:07 by dsiroten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	throw_error(char *message, t_loadgame *loadgame)
{
	ft_printf("%s\n", message);
	if (loadgame->mlx)
		mlx_terminate(loadgame->mlx);
	free_all(loadgame);
	exit(EXIT_FAILURE);
}

void	free_all(t_loadgame *loadgame)
{
	if (!loadgame)
		return ;
	if (loadgame->fd != -1)
		close(loadgame->fd);
	if (loadgame->read_map)
		ft_lstclear(&loadgame->read_map, free);
	if (loadgame->character)
		free(loadgame->character);
	if (loadgame->dungeon)
		free(loadgame->dungeon);
	if (loadgame->map)
		free_map(loadgame->map, loadgame->height);
	free(loadgame);
}

void	exit_game(void *param)
{
	t_loadgame	*loadgame;

	loadgame = param;
	mlx_terminate(loadgame->mlx);
	free_all(loadgame);
	exit(EXIT_SUCCESS);
}

void	exit_game_on_error(char *message, t_loadgame *loadgame)
{
	if (message)
		ft_putstr_fd(message, 0);
	if (loadgame->mlx)
		mlx_terminate(loadgame->mlx);
	free_all(loadgame);
	exit(EXIT_FAILURE);
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
