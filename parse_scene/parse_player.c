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

#include "../cub3d.h"
#include <math.h>

static	void	set_player(
		float heading,
		t_position *position,
		t_game_params *params)
{
	params->player.heading = heading;
	params->player.x = position->x;
	params->player.y = position->y;
}

static	float	parse_player_heading(char map_element)
{
	if (map_element == NORTH_PLAYER)
		return (NORTH_HEADING);
	if (map_element == SOUTH_PLAYER)
		return (SOUTH_HEADING);
	if (map_element == WEST_PLAYER)
		return (WEST_HEADING);
	if (map_element == EAST_PLAYER)
		return (EAST_HEADING);
	return (0);
}

static	void	parse_player_position(int row, int column, t_position *pos)
{
	pos->x = column * CUBE_SIDE + CUBE_SIDE / 2;
	pos->y = row * CUBE_SIDE + CUBE_SIDE / 2;
}

int				parse_player(t_game_params *params)
{
	int			row;
	int			column;
	char		**map;
	t_position	position;
	float		heading;

	row = 0;
	map = params->map;
	while (map[row])
	{
		column = 0;
		while (map[row][column])
		{
			if (is_player(map[row][column]))
			{
				parse_player_position(row, column, &position);
				heading = parse_player_heading(map[row][column]);
				set_player(heading, &position, params);
			}
			column++;
		}
		row++;
	}
	return (NO_ERROR);
}
