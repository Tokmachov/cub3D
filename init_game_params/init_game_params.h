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

#ifndef INIT_GAME_PARAMS_H
# define INIT_GAME_PARAMS_H

# include "../cub3d.h"
# include "../mlx/mlx.h"
# include <math.h>

int		init_mlx(t_game_params *params);
void	set_mlx_window_center(t_game_params *params);
void	set_distance_to_projection_screen(t_game_params *params);
int		set_textures_images(t_game_params *params);
int		set_sprites_images(t_game_params *params);
int		set_buffer_image(t_game_params *params);
int		set_hit_distances_arr(t_game_params *params);

#endif
