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
#include <math.h>

void	move_player(t_direction dir, t_player *player)
{
	float *x;
	float *y;

	x = &player->x;
	y = &player->y;
	if (dir == LEFT)
	{
		*x += PLAYER_PACE * cos(player->heading + M_PI / 2);
		*y += -1 * (PLAYER_PACE * sin(player->heading + M_PI / 2));
	}
	else if (dir == FORWARD)
	{
		*x += PLAYER_PACE * cos(player->heading);
		*y += -1 * (PLAYER_PACE * sin(player->heading));
	}
	else if (dir == RIGHT)
	{
		*x += PLAYER_PACE * cos(player->heading + 3 * M_PI / 2);
		*y += -1 * (PLAYER_PACE * sin(player->heading + 3 * M_PI / 2));
	}
	else if (dir == BACK)
	{
		*x += PLAYER_PACE * cos(player->heading + M_PI);
		*y += -1 * (PLAYER_PACE * sin(player->heading + M_PI));
	}
}

void	change_heading(t_direction side, t_player *player)
{
	float increment;

	if (side == LEFT)
		increment = PLAYER_TURN_INCREMENT;
	if (side == RIGHT)
		increment = -PLAYER_TURN_INCREMENT;
	increment_angle(&player->heading, increment);
}
