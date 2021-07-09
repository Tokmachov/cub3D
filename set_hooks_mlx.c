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

#include "mlx.h"
#include "cub3d.h"

void	set_hooks_mlx(t_game_params *params)
{
	mlx_loop_hook(params->mlx, render_next_frame, params);
	mlx_hook(params->window, 2, 1L << 0, handle_key, params);
	mlx_hook(params->window, 17, 0, close_through_red_cross, params);
}
