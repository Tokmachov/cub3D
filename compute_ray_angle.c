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
#include "libft/libft.h"

float	compute_ray_angle(t_game_params *params, int current_ray_number)
{
	float angle_increment;
	float start_angle;
	float ray_angle;

	angle_increment = PLAYER_FOV / params->window_width;
	start_angle = params->player.heading + PLAYER_FOV / 2;
	ray_angle = start_angle - angle_increment * current_ray_number;
	reduce_to_one_circle(&ray_angle);
	return (ray_angle);
}
