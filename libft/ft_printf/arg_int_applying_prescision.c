/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int_applying_prescision.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 12:55:45 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 16:15:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	positives_applying_prescision(t_specifiers specs)
{
	STRING	zero_str;
	STRING	result_str;
	int		zerosnum;
	int		prescision;

	if (specs.precision == PRESCISION_NOT_SET)
		prescision = 0;
	else
		prescision = specs.precision;
	zerosnum = prescision - ft_strlen(specs.arg_val_str);
	if (zerosnum > 0)
	{
		zero_str = make_filled_str(zerosnum, '0');
		result_str = ft_strjoin(zero_str, specs.arg_val_str);
		free(zero_str);
	}
	else
		result_str = ft_strdup(specs.arg_val_str);
	return (result_str);
}

static	int		calc_zeros_num(t_specifiers specs)
{
	int prescision;
	int zerosnum;

	if (specs.precision == PRESCISION_NOT_SET)
		prescision = 0;
	else
		prescision = specs.precision;
	zerosnum = prescision - ft_strlen(specs.arg_val_str + 1);
	return (zerosnum);
}

static	STRING	negatives_applying_prescision(t_specifiers specs)
{
	STRING	zero_str;
	STRING	result_str_no_minus;
	STRING	result_str;
	int		zerosnum;
	char	*minus_sign;

	zerosnum = calc_zeros_num(specs);
	if (zerosnum > 0)
	{
		zero_str = make_filled_str(zerosnum, '0');
		result_str_no_minus = ft_strjoin(zero_str, (specs.arg_val_str + 1));
		minus_sign = ft_strdup("-");
		result_str = ft_strjoin(minus_sign, result_str_no_minus);
		free(zero_str);
		free(result_str_no_minus);
		free(minus_sign);
	}
	else
		result_str = ft_strdup(specs.arg_val_str);
	return (result_str);
}

STRING			arg_int_applying_prescision(t_specifiers specs)
{
	STRING	result_str;

	if (*specs.arg_val_str == '-')
		result_str = negatives_applying_prescision(specs);
	else if (*specs.arg_val_str == '0' && specs.precision == 0)
		result_str = ft_strdup("");
	else
		result_str = positives_applying_prescision(specs);
	return (result_str);
}
