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
#include "mlx.h"

int	render_next_frame(void *params)
{
	void	*mlx;
	void	*window;
	t_image	img;

	mlx = ((t_game_params*)params)->mlx;
	window = ((t_game_params*)params)->window;
	img = ((t_game_params*)params)->buf_img;
	draw_walls_ceiling_and_floor(params);
	draw_sprites(params);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_do_sync(mlx);
	return (0);
}
