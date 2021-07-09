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

void	correct_resolution(t_game_params *params,
						int curr_width, int curr_height)
{
	if (params->window_width == curr_width ||
		params->window_height == curr_height)
	{
		params->window_width = curr_width;
		params->window_height = curr_height;
	}
	if (params->window_width < WINDOW_WIDTH_MIN)
		params->window_width = WINDOW_WIDTH_MIN;
	if (params->window_height < WINDOW_HEIGHT_MIN)
		params->window_height = WINDOW_HEIGHT_MIN;
}
