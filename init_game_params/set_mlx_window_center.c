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

#include "init_game_params.h"

void	set_mlx_window_center(t_game_params *params)
{
	int	win_width;
	int	win_height;

	win_width = params->window_width;
	win_height = params->window_height;
	params->window_center.x = win_width / 2;
	params->window_center.y = win_height / 2;
}
