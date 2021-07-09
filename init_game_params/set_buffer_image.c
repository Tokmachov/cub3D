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

int		set_buffer_image(t_game_params *params)
{
	params->buf_img.img = mlx_new_image(
			params->mlx,
			params->window_width,
			params->window_height);
	if (!params->buf_img.img)
		return (MALLOC_ER);
	params->buf_img.addr = mlx_get_data_addr(
			params->buf_img.img,
			&params->buf_img.bits_per_pixel,
			&params->buf_img.line_length,
			&params->buf_img.endian);
	if (!params->buf_img.addr)
		return (MALLOC_ER);
	return (NO_ERROR);
}
