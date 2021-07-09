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

#include "../libft/libft.h"
#include "../cub3d.h"

static	t_bool	are_rgb_colors_valid(int r, int g, int b)
{
	t_bool is_red_valid;
	t_bool is_green_valid;
	t_bool is_blue_valid;

	is_red_valid = (r >= 0 && r <= 255);
	is_green_valid = (g >= 0 && g <= 255);
	is_blue_valid = (b >= 0 && b <= 255);
	return (is_red_valid && is_green_valid && is_blue_valid);
}

static	char	*move_ptr_to_blue(char *str)
{
	str = skip_to_next_coma_separated_number_parameter(str);
	if (!str || !ft_isdigit(*str))
		return (NULL);
	return (str);
}

static	char	*move_ptr_to_green(char *str)
{
	str = skip_to_next_coma_separated_number_parameter(str);
	if (!str || !ft_isdigit(*str))
		return (NULL);
	return (str);
}

static	char	*move_ptr_to_red(char *str)
{
	if (str[1] != ' ')
		return (NULL);
	str++;
	str = skip_spaces(str);
	if (!ft_isdigit(*str))
		return (NULL);
	return (str);
}

int				parse_rgb(char *str, int *color)
{
	int r;
	int g;
	int b;

	if ((str = move_ptr_to_red(str)))
		r = parse_int_limited(str, 2000);
	if (str && (str = move_ptr_to_green(str)))
		g = parse_int_limited(str, 2000);
	if (str && (str = move_ptr_to_blue(str)))
		b = parse_int_limited(str, 2000);
	if (!str)
		return (RGB_PARS_ER);
	str = skip_digits(str);
	str = skip_spaces(str);
	if (!*str && are_rgb_colors_valid(r, g, b))
	{
		*color = create_rgb(0, r, g, b);
		return (NO_ERROR);
	}
	else
		return (RGB_PARS_ER);
}
