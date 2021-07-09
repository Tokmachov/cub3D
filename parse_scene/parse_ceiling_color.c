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

static	t_bool	is_ceiling_color_filled(t_game_params *params)
{
	return (params->ceiling_color != NOT_SET);
}

int				parse_ceiling_color(char *str, t_game_params *params)
{
	int color;
	int error_code;

	error_code = NO_ERROR;
	if (is_ceiling_color_filled(params))
	{
		error_code = DUPL_CFG_ER;
		return (error_code);
	}
	error_code = parse_rgb(str, &color);
	if (!is_error(error_code))
		params->ceiling_color = color;
	return (error_code);
}
