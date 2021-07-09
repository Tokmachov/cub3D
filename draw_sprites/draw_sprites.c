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
#include <math.h>

static	void	swap(t_sprite *sprite1, t_sprite *sprite2)
{
	t_sprite tmp;

	tmp = *sprite1;
	*sprite1 = *sprite2;
	*sprite2 = tmp;
}

static	void	sort_ascending(t_sprite arr[], int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j].distance > arr[j + 1].distance)
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void			draw_sprites(t_game_params *params)
{
	int i;

	i = 0;
	while (i < params->sprites_count)
	{
		compute_sprite(&params->sprites[i], params);
		i++;
	}
	sort_ascending(params->sprites, params->sprites_count);
	i = params->sprites_count;
	while (i--)
		draw_sprite(&params->sprites[i], params);
}
