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

void	set_sprites_img_values_null(t_game_params *params)
{
	int i;

	i = 0;
	while (i < params->sprites_count)
	{
		params->sprites[i].img.img_ptr = NULL;
		params->sprites[i].img.location_dir = NULL;
		i++;
	}
}
