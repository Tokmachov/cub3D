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
#include "libft/libft.h"

static	t_bool	is_wall_hit(t_position *position, t_game_params *params)
{
	int row;
	int column;

	row = position->y / CUBE_SIDE;
	column = position->x / CUBE_SIDE;
	if (params->map[row][column] == WALL)
		return (true);
	else
		return (false);
}

static	t_bool	is_in_map(t_position *position, t_game_params *params)
{
	int row;
	int column;
	int max_row;
	int max_column;

	row = position->y / CUBE_SIDE;
	column = position->x / CUBE_SIDE;
	max_column = params->columns_count - 1;
	max_row = params->rows_count - 1;
	if (row > max_row || column > max_column || row < 0 || column < 0)
		return (false);
	return (true);
}

void			compute_hit_pos(t_position *first_hit,
					float x_increment,
					float y_increment,
					t_game_params *params)
{
	while (is_in_map(first_hit, params) && !is_wall_hit(first_hit, params))
	{
		first_hit->x += x_increment;
		first_hit->y += y_increment;
	}
}
