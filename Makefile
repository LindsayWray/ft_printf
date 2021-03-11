# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lwray <lwray@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/25 13:28:08 by lwray         #+#    #+#                  #
#    Updated: 2021/03/11 11:53:50 by lwray         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = 	flags_s.c \
		ft_putnbr_hexa.c \
		filler.c \
		ft_putnbr_uns.c \
		flags_u.c \
		ft_putnstr.c \
		flagcheck.c \
		flags_x.c \
		ft_putptr.c \
		flags_c.c \
		ft_conversion.c \
		hexa_len.c \
		ft_printf.c	\
		is_specifier.c \
		flags_d.c \
		ft_putchar.c \
		flags_p.c \
		ft_putnbr.c \
		char_count.c \
		ft_strlen.c \
		flags_null.c \
		flags_f_bonus.c \
		ft_putdecimal_bonus.c

FLAGS = -Wall -Wextra -Werror

REG_OBJS = ${SRCS:.c=.o}

OBJS = $(REG_OBJS)

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o}

.PHONY: all
all: ${NAME}

$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

.PHONY: clean
clean:
	rm -f ${OBJS}

.PHONY: fclean
fclean: clean
	rm -f ${NAME}

.PHONY: re
re: fclean all

.PHONY: bonus
bonus:
	$(MAKE) all
