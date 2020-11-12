# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 14:25:59 by ichejra           #+#    #+#              #
#    Updated: 2020/01/18 23:18:16 by ichejra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRC=  c_conv.c\
	   check_flag.c\
	   convs.c\
	   d_conv.c\
	   execdot.c\
	   f_dig.c\
	   f_dot.c\
	   f_min_utils.c\
	   f_min.c\
	   f_star.c\
	   f_zero.c\
	   ft_count.c\
	   ft_dectohex.c\
	   ft_printf_utils.c\
	   ft_printf.c\
	   len.c\
	   p_conv.c\
	   p_utils.c\
	   per_conv.c\
	   print_functions.c\
	   print_sp_when_dot_star.c\
	   print_sp.c\
	   print_zero_utils.c\
	   print_zero_when_dot_star.c\
	   print_zero.c\
	   s_conv.c\
	   s_precision.c\
	   d_precision.c\
	   u_precision.c\
	   c_precision.c\
	   per_precision.c\
	   p_precision.c\
	   x_precision.c\
	   upper_x_precision.c\
	   u_conv.c\
	   when_dot.c\
	   x_conv.c\
	   xx_conv.c\

OBJ = $(SRC:.c=.o)

CFLAGS =  -Wall -Wextra -Werror -c

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
