# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luyang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:43:14 by luyang            #+#    #+#              #
#    Updated: 2023/11/21 17:14:27 by luyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_flags.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_ptr.c ft_print_str.c ft_print_unsigned.c ft_print_utils.c ft_printf.c 
NAME = libftprintf.a
CC = gcc
AR = ar rcs
RM = rm -rf
CCFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

%.o:		%.c
		$(CC) $(CCFLAGS) -c $< -o $@
all:		$(NAME)
$(NAME):	$(OBJS) $(LIBFT)
		cp $(LIBFT) $(NAME)
			$(AR) $(NAME) $(OBJS)
$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		make -C $(LIBFT_DIR) clean
		$(RM) $(OBJS)
fclean:		clean
		make -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)
re:		fclean all
.PHONY:		all clean fclean re libft

