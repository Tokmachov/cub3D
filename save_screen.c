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
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static	int				my_get_color(t_game_params *params, int x, int y)
{
	char *dst;

	dst = params->buf_img.addr + (
		y * params->buf_img.line_length + x * (
			params->buf_img.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

static	void			init_header(
	unsigned char *header_arr, int size, t_game_params *params, int temp)
{
	header_arr[0] = (unsigned char)'B';
	header_arr[1] = (unsigned char)'M';
	header_arr[2] = (unsigned char)size;
	header_arr[3] = (unsigned char)(size >> 8);
	header_arr[4] = (unsigned char)(size >> 16);
	header_arr[5] = (unsigned char)(size >> 24);
	header_arr[10] = (unsigned char)54;
	header_arr[14] = (unsigned char)40;
	header_arr[18] = (unsigned char)temp;
	header_arr[19] = (unsigned char)(temp >> 8);
	header_arr[20] = (unsigned char)(temp >> 16);
	header_arr[21] = (unsigned char)(temp >> 24);
	header_arr[22] = (unsigned char)params->window_height;
	header_arr[23] = (unsigned char)(params->window_height >> 8);
	header_arr[24] = (unsigned char)(params->window_height >> 16);
	header_arr[25] = (unsigned char)(params->window_height >> 24);
	header_arr[26] = (unsigned char)1;
	header_arr[28] = (unsigned char)24;
}

static	void			get_screenshot(t_game_params *params, int fd, int res)
{
	int	color;
	int	x;
	int	y;
	int	size_x;

	color = 0;
	x = 0;
	y = params->window_height - 1;
	size_x = res;
	while (y >= 0)
	{
		while (x < size_x)
		{
			color = my_get_color(params, x, y);
			write(fd, &color, 3);
			x++;
		}
		y--;
		x = 0;
	}
}

int						make_screen(t_game_params *params)
{
	int				fd;
	unsigned char	header_arr[54];
	int				count;
	int				size;
	int				temp_res;

	temp_res = params->window_width;
	if (params->window_width % 4)
		temp_res = params->window_width - (params->window_width % 4);
	size = temp_res * params->window_height + 54;
	count = 0;
	if ((fd = open("cub3D_screen_shot.bmp", O_RDWR | O_CREAT, 0666)) < 0)
		return (-1);
	while (count < 54)
	{
		header_arr[count] = (unsigned char)0;
		count++;
	}
	init_header(header_arr, size, params, temp_res);
	write(fd, header_arr, 54);
	get_screenshot(params, fd, temp_res);
	close(fd);
	exit(0);
}
