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

void	draw_walls_ceiling_and_floor(t_game_params *params)
{
	int				slice_num;
	t_wall_slice	wall_slice;

	slice_num = 0;
	while (slice_num < params->window_width)
	{
		compute_wall_slice(&wall_slice, slice_num, params);
		params->hit_distances[slice_num] = wall_slice.hit_distance;
		draw_ceiling_slice(params, wall_slice, slice_num);
		draw_textured_wall_slice(params, &wall_slice, slice_num);
		draw_floor_slice(params, wall_slice, slice_num);
		slice_num++;
	}
}
