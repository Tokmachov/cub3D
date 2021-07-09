/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:59:20 by mac               #+#    #+#             */
/*   Updated: 2020/06/23 15:36:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	STRING	get_value_for_arg_type(char argtype, va_list args)
{
	t_parse_func	f;
	STRING			arg_value;

	f = parse_func_for_id(argtype);
	if (!f)
		return (NULL);
	arg_value = f(args);
	return (arg_value);
}

static	char	arg_type_adjusted_with_len_flag(t_specifiers specs)
{
	if (specs.is_ll == true && (specs.arg_type == 'd' || specs.arg_type == 'i'))
		return ('L');
	else if (specs.is_l == true && (specs.arg_type == 'd' \
		|| specs.arg_type == 'i'))
		return ('l');
	else
		return (specs.arg_type);
}

static	t_bool	is_parsable_as_arg_val(char c)
{
	if (is_arg_type(c) || c == '%' || (!is_flag(c) && !ft_isdigit(c)))
		return (true);
	else
		return (false);
}

int				parse_arg(STRING str, t_specifiers **specs, va_list args)
{
	char arg_type;

	if (is_parsable_as_arg_val(*str) && *str != '\0')
	{
		if (is_arg_type(*str))
		{
			(*specs)->arg_type = *str;
			arg_type = arg_type_adjusted_with_len_flag(**specs);
			(*specs)->arg_val_str = get_value_for_arg_type(arg_type, args);
		}
		else if ((!is_flag(*str) && !ft_isdigit(*str)) || *str == '%')
		{
			(*specs)->arg_type = 'c';
			(*specs)->arg_val_str = ft_substr(str, 0, 1);
		}
		if ((*specs)->arg_val_str == NULL)
		{
			free(*specs);
			*specs = NULL;
		}
		return (1);
	}
	else
		return (0);
}
