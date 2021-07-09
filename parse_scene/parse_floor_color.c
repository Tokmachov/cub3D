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
#include "../libft/libft.h"

static	t_bool	is_floor_color_filled(t_game_params *params)
{
	if (params->floor_color == NOT_SET)
		return (false);
	else
		return (true);
}

int				parse_floor_color(char *str, t_game_params *params)
{
	int color;
	int error_code;

	error_code = NO_ERROR;
	if (is_floor_color_filled(params))
	{
		error_code = DUPL_CFG_ER;
		return (error_code);
	}
	error_code = parse_rgb(str, &color);
	if (!is_error(error_code))
	{
		params->floor_color = color;
		return (error_code);
	}
	else
		return (error_code);
}
