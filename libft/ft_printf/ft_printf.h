/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:22:42 by mac               #+#    #+#             */
/*   Updated: 2020/06/24 16:13:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>
# include <stdint.h>

# define ARG_TYPES "cspdiuxX"
# define FLAGS "-0.*l"
# define ERROR -1
# define PRESCISION_NOT_SET -1
# define HEX_PREFIX "0x"

typedef struct		s_spicifiers
{
	t_bool			is_left_aligned;
	t_bool			is_zero_padded;
	int				width;
	int				precision;
	char			arg_type;
	t_bool			is_l;
	t_bool			is_ll;
	char			*arg_val_str;
}					t_specifiers;

typedef struct		s_printable_str
{
	size_t			strlen;
	STRING			str;
}					t_printable_str;

typedef	STRING		(*t_parse_func)(va_list args);

typedef struct		s_func_and_id
{
	char			id;
	t_parse_func	f;
}					t_func_and_id;

int					ft_printf(const char *format, ...);
/*
**ft_printf
*/
t_printable_str		**make_printable_strs(STRING format, va_list args);
int					count_printed_chrs(t_printable_str **printable);
void				print(t_printable_str **printable);
void				free_printables(t_printable_str **printable);
/*
**make_printable_strs
*/
STRING				*split_to_comps(STRING format);
t_printable_str		**convert_to_printables(STRING *comps, va_list args);
void				free_comps(STRING *comps);
/*
**split_to_comps
*/
STRING				move_ptr_past_comp(char *ptr);
STRING				get_comp(STRING format);
/*
**convert_to_printables
*/
t_printable_str		*convert_to_printable(STRING comp, va_list args);
t_printable_str		*make_printable_from_specs_comp(STRING comp, va_list args);
/*
**make_printable_from_specs_comp
*/
t_specifiers		*parse_specs(STRING comp, va_list args);
STRING				convert_specs_to_str(t_specifiers specs);
t_printable_str		*init_printable(STRING str, size_t strlen);
/*
**parse_specs
*/
int					parse_flag(STRING fl, t_specifiers *specs);
int					parse_width(STRING str, t_specifiers *specs, va_list args);
int					parse_prescision(STRING str, \
	t_specifiers *specs, va_list args);
int					parse_arg(STRING str, t_specifiers **specs, va_list args);
/*
**parse_arg
*/
STRING				parse_c_arg(va_list args);
STRING				parse_s_arg(va_list args);
STRING				parse_int_arg(va_list args);
STRING				parse_ll_arg(va_list args);
/*
**parse_specs
*/
t_parse_func		parse_func_for_id(char id);
t_bool				is_flag(char c);
t_bool				is_arg_type(char c);
STRING				ft_itoa_hex(unsigned int num, t_bool is_uppercase);
STRING				ft_itoa_u(unsigned int n);
STRING				ft_itoa_p(uintmax_t p);
STRING				ft_itoa_ll(long long int n);
STRING				parse_p_arg(va_list args);
STRING				parse_u_arg(va_list args);
STRING				parse_x_arg(va_list args);
STRING				parse_capital_x_arg(va_list args);
/*
**make_printable_str
*/
STRING				arg_applaying_prescision(t_specifiers specs);
STRING				arg_formatted(t_specifiers specs);
/*
**arg_applaying_prescision
*/
STRING				arg_s_applying_prescision(t_specifiers specs);
STRING				arg_int_applying_prescision(t_specifiers specs);
STRING				arg_p_applying_prescision(t_specifiers specs);
/*
**filled_width
*/
STRING				width_filled_with_padding_and_int_arg(int padding_len, \
	t_specifiers specs);
STRING				width_filled_with_padding_and_s_arg(int padding_len, \
	t_specifiers specs);
STRING				width_filled_with_padding_and_c_arg(int padding_len, \
	t_specifiers specs);
STRING				width_filled_with_padding_and_p_arg(t_specifiers specs);
STRING				right_aligned_str(int padding_len, t_bool is_zero_padded, \
	STRING arg);
STRING				left_aligned_str(int padding_len, STRING arg);
int					calc_padding_len(t_specifiers specs);
STRING				make_filled_str(int len, char fillingchr);

#endif
