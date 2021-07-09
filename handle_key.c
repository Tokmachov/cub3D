/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjolynn <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:55:23 by sjolynn           #+#    #+#             */
/*   Updated: 2020/08/25 16:41:18 by sjolynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <unistd.h>

int	handle_key(int key, void *params)
{
	t_player *player_ptr;

	player_ptr = &((t_game_params*)params)->player;
	if (key == W_KEY)
		move_player(FORWARD, player_ptr);
	if (key == D_KEY)
		move_player(RIGHT, player_ptr);
	if (key == S_KEY)
		move_player(BACK, player_ptr);
	if (key == A_KEY)
		move_player(LEFT, player_ptr);
	if (key == LEFT_ARROW_KEY)
		change_heading(LEFT, player_ptr);
	if (key == RIGHT_ARROW_KEY)
		change_heading(RIGHT, player_ptr);
	if (key == ESC_KEY)
		exit_cleanly(params);
	return (0);
}
