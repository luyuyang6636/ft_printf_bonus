# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luyang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 21:27:56 by luyang            #+#    #+#              #
#    Updated: 2023/06/20 22:10:55 by luyang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putstr_fd.c ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c
BONUSSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = ${SRCS:.c=.o}
BONUSOBJ = ${BONUSSRCS:.c=.o}
CC = gcc
FLAG = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a

%.o: %.c
	${CC} ${FLAG} -c -o $@ $<

${NAME}: ${OBJ}
	$(AR) rcs $@ $?

bonus: ${OBJ} ${BONUSOBJ}
	$(AR) rcs $(NAME) $?

all: ${NAME}

clean:
	${RM} ${OBJ} ${BONUSOBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
