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
#include "mlx/mlx.h"

int		open_window(t_game_params *params)
{
	void	*mlx;
	int		win_width;
	int		win_height;

	mlx = params->mlx;
	win_width = params->window_width;
	win_height = params->window_height;
	params->window = mlx_new_window(mlx, win_width, win_height, "cub3D");
	if (!params->window)
		return (MALLOC_ER);
	return (NO_ERROR);
}
