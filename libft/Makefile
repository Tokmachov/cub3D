# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjolynn <sjolynn@student.21-school.ru      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/03 17:16:27 by sjolynn           #+#    #+#              #
#    Updated: 2020/08/25 11:29:44 by sjolynn          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_OF_LIBFT = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
ft_lstiter.c ft_lstmap.c ft_minints.c ft_maxints.c ft_abs.c \
get_next_line.c

SRCS_OF_PRINTF = $(addprefix ft_printf/, ft_printf.c \
	make_printable_strs.c \
	split_to_comps.c \
	convert_to_printables.c \
	free_comps.c \
	move_ptr_past_comp.c \
	get_comp.c \
	convert_to_printable.c \
	make_printable_from_specs_comp.c \
	parse_specs.c \
	convert_specs_to_str.c \
	parse_flag.c \
	parse_width.c \
	parse_prescision.c \
	parse_arg.c \
	parse_c_arg.c \
	parse_s_arg.c \
	parse_int_arg.c \
	parse_ll_arg.c \
	parse_p_arg.c \
	parse_u_arg.c \
	parse_x_arg.c \
	parse_capital_x_arg.c \
	parse_func_for_id.c \
	init_printable.c \
	arg_applaying_prescision.c \
	arg_s_applying_prescision.c \
	arg_p_applying_prescision.c \
	arg_int_applying_prescision.c \
	arg_formatted.c \
	width_filled_with_padding_and_int_arg.c \
	width_filled_with_padding_and_s_arg.c \
	width_filled_with_padding_and_p_arg.c \
	width_filled_with_padding_and_c_arg.c \
	right_aligned_str.c \
	left_aligned_str.c \
	calc_padding_len.c \
	count_printed_chrs.c \
	print.c \
	free_printables.c \
	is_flag.c \
	is_arg_type.c \
  	ft_itoa_hex.c \
	ft_itoa_ll.c \
	make_filled_str.c \
	ft_itoa_u.c \
	ft_itoa_p.c)


HEADER_LIBFT = libft.h

HEADER_PRINTF = ft_printf/ft_printf.h

OBJS_LIBFT = $(SRCS_OF_LIBFT:.c=.o)

OBJS_PRINTF = $(SRCS_OF_PRINTF:.c=.o) 

OBJS = $(OBJS_LIBFT) $(OBJS_PRINTF)

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADER_LIBFT) $(HEADER_PRINTF)
	$(CC) $(CFLAGS) -I. -Ift_printf -g $< -o $@

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

